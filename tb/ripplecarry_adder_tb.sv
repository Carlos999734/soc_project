//====================================================
// Testbench: ripplecarry_adder_tb
// Project: SoC Project
// File: ripplecarry_adder_tb.sv
// Author: Carlos Diaz
// Description:
//   Testbench for Ripple-Carry Adder module.
//   Verifies correctness of the adder using randomized test cases.
//====================================================

`timescale 1ns/1ps
import soc_pkg::*;

module ripplecarry_adder_tb();

    // Testbench signals
    data_t tb_a, tb_b, tb_sum;
    logic  tb_carryOut;
    logic [DATA_WIDTH:0] expected;
    data_t prev_a, prev_b;
    int rand_val;

    int pass_count = 0;
    int fail_count = 0;
    bit fatal_on_error = 0; // Set to 1 to abort on first failure
    bit done_flag = 0;

    // Clock generation
    logic clk = 0;
    always #5 clk = ~clk;  // 100ps clock period

    // Number of test runs (can be changed for more exhaustive testing)
    localparam int NUM_TESTS = 20;

    // DUT instantiation
    ripplecarry_adder dut (
        .a(tb_a),
        .b(tb_b),
        .sum(tb_sum),
        .carryOut(tb_carryOut)
    );

    // Main test process
    initial begin
        $display("Starting testbench for ripple_carry_adder");

        // Synchronize testbench to clock
        @(posedge clk);
        @(posedge clk);
        @(posedge clk);

        for (int i = 0; i < NUM_TESTS; i++) begin
            // Phase 1: Check previous cycle's result (skip on first iteration)
            if (i > 0) begin
                if ({tb_carryOut, tb_sum} !== expected) begin
                    $error("FAIL: a=%0d b=%0d → sum=%0d carry=%0b (expected sum=%0d carry=%0b)",
                        prev_a, prev_b, tb_sum, tb_carryOut, expected[DATA_WIDTH-1:0], expected[DATA_WIDTH]);
                    fail_count++;
                    if (fatal_on_error) $fatal(1, "Aborting on first error.");
                end else begin
                    pass_count++;
                end
            end

            // Phase 2: Apply new inputs
            @(posedge clk);
            rand_val = $urandom_range(0, (1 << DATA_WIDTH)-1);
            tb_a = rand_val[DATA_WIDTH-1:0];
            rand_val = $urandom_range(0, (1 << DATA_WIDTH)-1);
            tb_b = rand_val[DATA_WIDTH-1:0];

            // Phase 3: Compute expected result for new inputs
            expected = tb_a + tb_b;
            prev_a = tb_a;
            prev_b = tb_b;
        end

        // Report results
        $display("Testbench complete: %0d passed, %0d failed", pass_count, fail_count);
        done_flag = 1;
        $finish;
    end

    // Monitor signal activity and generate waveform
    initial begin
        $monitor("Time %0t: a=%b b=%b → sum=%b carry=%b", $time, tb_a, tb_b, tb_sum, tb_carryOut);
        $dumpfile("../../sim/waveforms/ripplecarry_adder_tb.vcd");
        $dumpvars(0, ripplecarry_adder_tb);
    end

    // Simulation timeout to ensure VCD gets written
    initial begin
        #50000;
        if (!done_flag) begin
            $display("Timeout reached — terminating simulation.");
            $finish;
        end
    end

endmodule