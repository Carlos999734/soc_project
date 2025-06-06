//====================================================
// Testbench: halfadder_tb
// Project: SoC Project
// File: halfadder_tb.sv
// Author: Carlos Diaz
// Description:
//   Testbench for Half Adder module.
//   Verifies correct functionality for all input combinations.
//====================================================

`timescale 1ns/1ps
import soc_pkg::*;

module halfadder_tb();

    // Testbench signals declaration
    logic tb_a, tb_b, tb_sum, tb_carry;

    // DUT instantiation
    halfadder half_adder (
        .a(tb_a),
        .b(tb_b),
        .sum(tb_sum),
        .carry(tb_carry)
    );

    // Toggle to control whether simulation should stop on first error (set to 0 to disable)
    bit fatal_on_error = 0;
    bit done_flag = 0;

    // Declare input vector to iterate through all input combinations (2 bits)
    logic [1:0] input_vec;

    // Main stimulus and output validation process
    initial begin
        // Display header information
        $display("Time | a b | sum | carry");
        $display("Testbench for half adder");

        // Loop through all possible input combinations (00, 01, 10, 11)
        for (int unsigned i = 0; i < 4; i++) begin
            input_vec = i[1:0];        // Assign lower 2 bits
            tb_a = input_vec[1];       // Extract bit 1 for tb_a
            tb_b = input_vec[0];       // Extract bit 0 for tb_b
            #1;                        // Wait for signals to propagate

            // Check outputs based on current input combination
            case (input_vec)
                2'b00: if (tb_sum !== 0 || tb_carry !== 0) begin
                           $error("Failed: 00 -> sum=%b carry=%b", tb_sum, tb_carry);
                           if (fatal_on_error) $fatal(1, "Aborting on first error.");
                       end
                2'b01: if (tb_sum !== 1 || tb_carry !== 0) begin
                           $error("Failed: 01 -> sum=%b carry=%b", tb_sum, tb_carry);
                           if (fatal_on_error) $fatal(1, "Aborting on first error.");
                       end
                2'b10: if (tb_sum !== 1 || tb_carry !== 0) begin
                           $error("Failed: 10 -> sum=%b carry=%b", tb_sum, tb_carry);
                           if (fatal_on_error) $fatal(1, "Aborting on first error.");
                       end
                2'b11: if (tb_sum !== 0 || tb_carry !== 1) begin
                           $error("Failed: 11 -> sum=%b carry=%b", tb_sum, tb_carry);
                           if (fatal_on_error) $fatal(1, "Aborting on first error.");
                       end
                default: $error("Invalid input combination.");
            endcase
        end

        // Report completion of testbench
        $display("Testbench completed");
        done_flag = 1;
        $finish;
    end

    // Dump waveform data for viewing signal transitions in a waveform viewer
    initial begin
        $dumpfile("../../sim/waveforms/halfadder_tb.vcd");
        $dumpvars(0, halfadder_tb);
    end

    // Monitor signal changes and print them during simulation
    initial begin
        $monitor("Monitor: %4t | a=%b b=%b -> sum=%b , carry=%b", $time, tb_a, tb_b, tb_sum, tb_carry);
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