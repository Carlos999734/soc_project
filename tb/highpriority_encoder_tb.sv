//====================================================
// Testbench: highpriority_encoder_tb
// Project: SoC Project
// File: highpriority_encoder_tb.sv
// Author: Carlos Diaz
// Description:
//   Testbench for High-Priority Encoder module.
//   Verifies correct functionality for all input combinations.
//====================================================

`timescale 1ns/1ps
import soc_pkg::*;

module highpriority_encoder_tb();

    // Testbench signals declaration
    logic tb_a, tb_b, tb_c, tb_d;
    logic [1:0] tb_out;

    // DUT instantiation
    highpriority_encoder encoder (
        .a(tb_a),
        .b(tb_b),
        .c(tb_c),
        .d(tb_d),
        .out(tb_out)
    );

    // Toggle to control whether simulation should stop on first error (set to 0 to disable)
    bit fatal_on_error = 0;
    bit done_flag = 0;

    // Declare input vector to iterate through all input combinations (4 bits)
    logic [3:0] input_vec;

    // Main stimulus and output validation process
    initial begin
        // Display header information
        $display("Time | a b c d | out");
        $display("Testbench for highpriority_encoder");

        // Loop through all possible input combinations (0000 to 1111)
        for (int unsigned i = 0; i < 16; i++) begin
            input_vec = i[3:0];          // Explicitly assign lower 4 bits
            tb_a = input_vec[0];         // Extract bit 0 for tb_a
            tb_b = input_vec[1];         // Extract bit 1 for tb_b
            tb_c = input_vec[2];         // Extract bit 2 for tb_c
            tb_d = input_vec[3];         // Extract bit 3 for tb_d
            #1;                          // Wait for signals to propagate

            // Check outputs based on current input combination
            if (tb_d) begin
                if (tb_out !== 2'b11) begin
                    $error("Failed: %b -> out=%b", input_vec, tb_out);
                    if (fatal_on_error) $fatal(1, "Aborting on first error.");
                end
            end else if (tb_c) begin
                if (tb_out !== 2'b10) begin
                    $error("Failed: %b -> out=%b", input_vec, tb_out);
                    if (fatal_on_error) $fatal(1, "Aborting on first error.");
                end
            end else if (tb_b) begin
                if (tb_out !== 2'b01) begin
                    $error("Failed: %b -> out=%b", input_vec, tb_out);
                    if (fatal_on_error) $fatal(1, "Aborting on first error.");
                end
            end else if (tb_a) begin
                if (tb_out !== 2'b00) begin
                    $error("Failed: %b -> out=%b", input_vec, tb_out);
                    if (fatal_on_error) $fatal(1, "Aborting on first error.");
                end
            end else begin
                if (tb_out !== 2'b00) begin
                    $error("Failed: %b -> out=%b", input_vec, tb_out);
                    if (fatal_on_error) $fatal(1, "Aborting on first error.");
                end
            end
        end

        // Report completion of testbench
        $display("Testbench completed");
        done_flag = 1;
        $finish;
    end

    // Dump waveform data for viewing signal transitions in a waveform viewer
    initial begin
        $dumpfile("../../sim/waveforms/highpriority_encoder_tb.vcd");
        $dumpvars(0, highpriority_encoder_tb);
    end

    // Monitor signal changes and print them during simulation
    initial begin
        $monitor("Monitor: %4t | a=%b b=%b c=%b d=%b -> out=%b", $time, tb_a, tb_b, tb_c, tb_d, tb_out);
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
