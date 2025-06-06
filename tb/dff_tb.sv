//====================================================
// Testbench: dff_tb
// Project: SoC Project
// File: dff_tb.sv
// Author: Carlos Diaz
// Description:
//   Testbench for D Flip-Flop module.
//   Verifies correct behavior of flip-flop on clock edges.
//====================================================

`timescale 1ns/1ps
import soc_pkg::*;

module dff_tb();

    // Testbench signals
    logic tb_d, tb_out;

    int pass_count = 0;
    int fail_count = 0;
    bit fatal_on_error = 0; // Set to 1 to abort on first failure

    // Clock generation (100ps period)
    logic tb_clk = 0;
    always #5 tb_clk = ~tb_clk;

    // Number of test runs (can be changed for more exhaustive testing)
    localparam int NUM_TESTS = 100;

    // DUT instantiation
    dff dut (
        .d(tb_d),
        .clk(tb_clk),
        .out(tb_out)
    );

    // Previous output for checking DFF behavior
    logic prev_out;
    int rand_val;
    bit done_flag = 0;

    // Main test process
    initial begin
        $display("Starting testbench for dff");

        // Initialize
        tb_d = 0;
        prev_out = 0;
        rand_val = 0;

        // Synchronize testbench to clock
        @(posedge tb_clk);
        @(posedge tb_clk);
        @(posedge tb_clk);

        for (int i = 0; i < NUM_TESTS; i++) begin
            // Phase 1: Check previous cycle's result (skip on first iteration)
            if (i > 0) begin
                if (tb_out !== prev_out) begin
                    $error("FAIL: d=%b clk=%b → out=%b (expected out=%b)", tb_d, tb_clk, tb_out, prev_out);
                    fail_count++;
                    if (fatal_on_error) $fatal(1, "Aborting on first error.");
                end else begin
                    pass_count++;
                end
            end

            // Phase 2: Generate new input (sync to negedge clk)
            @(negedge tb_clk);
            rand_val = $urandom_range(0, 1);
            tb_d = rand_val[0];

            // Phase 3: Update expected output after next clock edge
            @(posedge tb_clk);
            prev_out = tb_d;
        end

        $display("Testbench complete: %0d passed, %0d failed", pass_count, fail_count);
        done_flag = 1;
        $finish;
    end

    // Monitoring and waveform dumping
    initial begin
        $dumpfile("../../sim/waveforms/dff_tb.vcd");
        $dumpvars(0, dff_tb);
    end

    // Safe display monitor for testbench (non-synthesizable)
    always @(posedge tb_clk) begin
        $display("Time %0t: d=%b clk=%b → out=%b", $time, tb_d, tb_clk, tb_out);
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
