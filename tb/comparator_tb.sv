//====================================================
// Testbench: comparator_tb
// Project: SoC Project
// File: comparator_tb.sv
// Author: Carlos Diaz
// Description:
//   Testbench for comparator module.
//   Randomized tests to verify comparator functionality.
//====================================================

`timescale 1ns/1ps
import soc_pkg::*;

module comparator_tb();

    // Testbench signals declaration
    data_t tb_a, tb_b;
    logic tb_equal, tb_less, tb_greater;

    data_t ref_a, ref_b;
    logic [2:0] ref_result;

    // DUT instantiation
    comparator dut (
        .a(tb_a), .b(tb_b),
        .equal(tb_equal), .less(tb_less), .greater(tb_greater)
    );

    // Toggle to control whether simulation should stop on first error (set to 0 to disable)
    bit fatal_on_error = 0;
    bit done_flag = 0;
    int rand_val;

    localparam int NUM_TESTS = 20;

    initial begin
        // Display header information
        $display("Testbench for comparator");
        $display("Time | a b (bin) | equal | less | greater");

        // Randomized testing loop
        for (int i = 0; i < NUM_TESTS; i++) begin
            rand_val = $urandom_range(0, (1 << DATA_WIDTH)-1);
            ref_a = rand_val[DATA_WIDTH-1:0];
            rand_val = $urandom_range(0, (1 << DATA_WIDTH)-1);
            ref_b = rand_val[DATA_WIDTH-1:0];

            // Drive DUT inputs
            tb_a = ref_a;
            tb_b = ref_b;
            #1;

            // Reference model (using inline compare logic)
            ref_result[2] = (&(ref_a == ref_b)) ? 1'b1 : 1'b0;
            ref_result[1] = (&(ref_a < ref_b))  ? 1'b1 : 1'b0;
            ref_result[0] = (&(ref_a > ref_b))  ? 1'b1 : 1'b0;

            if (tb_equal !== ref_result[2] ||
                tb_less   !== ref_result[1] ||
                tb_greater!== ref_result[0]) begin
                $error("FAIL: a=%0d b=%0d -> DUT equal=%b less=%b greater=%b | REF equal=%b less=%b greater=%b",
                        tb_a, tb_b,
                        tb_equal, tb_less, tb_greater,
                        ref_result[2], ref_result[1], ref_result[0]);
                if (fatal_on_error) $fatal(1, "Aborting on first error.");
            end
        end

        // Report completion of testbench
        $display("Testbench completed");
        done_flag = 1;
        $finish;
    end

    // Dump waveform data for viewing signal transitions in a waveform viewer
    initial begin
        $dumpfile("../../sim/waveforms/comparator_tb.vcd");
        $dumpvars(0, comparator_tb); // Dump all testbench signals
    end

    // Monitor signal changes and print them during simulation
    initial begin
        $monitor("Monitor: %4t | a=%b b=%b -> equal=%b , less=%b , greater=%b",
                  $time, tb_a, tb_b, tb_equal, tb_less, tb_greater);
    end

    // Simulation timeout to ensure VCD gets written
    initial begin
        #5000;
        if (!done_flag) begin
            $display("Timeout reached — terminating simulation.");
            $finish;
        end
    end

endmodule