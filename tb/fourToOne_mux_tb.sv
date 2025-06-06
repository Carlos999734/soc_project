//====================================================
// Testbench: fourToOne_mux_tb
// Project: SoC Project
// File: fourToOne_mux_tb.sv
// Author: Carlos Diaz
// Description:
//   Testbench for 4-to-1 multiplexer module.
//   Verifies correct functionality for all select cases.
//====================================================

`timescale 1ns/1ps
import soc_pkg::*;

module fourToOne_mux_tb();

    // Declare testbench signals for data inputs, select input, and output
    data_t tb_D0, tb_D1, tb_D2, tb_D3, tb_out;
    logic [1:0] tb_sel;
    data_t ref_out;

    // Instantiate the 4-to-1 multiplexer module
    fourToOne_mux mux (
        .D0(tb_D0), .D1(tb_D1), .D2(tb_D2), .D3(tb_D3),
        .out(tb_out), .sel(tb_sel)
    );

    // Toggle to control whether simulation should stop on first error (set to 0 to disable)
    bit fatal_on_error = 0;
    bit done_flag = 0;

    localparam int NUM_TESTS = 4;

    // Main stimulus and output validation process
    initial begin
        // Initialize input values before simulation begins
        tb_D0 = 8'hAA;
        tb_D1 = 8'hBB;
        tb_D2 = 8'hCC;
        tb_D3 = 8'hDD;
        #1; // allow all D* values to propagate

        // Display header information
        $display("Time | sel | out |");
        $display("Testbench for 4 to 1 mux");

        // Loop through all possible input combinations (00, 01, 10, 11)
        for (int i = 0; i < NUM_TESTS; i++) begin
            // Assign select line and wait for output to stabilize
            tb_sel = i;
            #1;

            // Reference model using case statement
            case (tb_sel)
                2'b00: ref_out = tb_D0;
                2'b01: ref_out = tb_D1;
                2'b10: ref_out = tb_D2;
                2'b11: ref_out = tb_D3;
                default: ref_out = {DATA_WIDTH{1'b0}};
            endcase

            // Check outputs against reference
            if (tb_out !== ref_out) begin
                $error("FAIL: sel=%b -> out=%h (expected %h)", tb_sel, tb_out, ref_out);
                if (fatal_on_error) $fatal(1, "Aborting on first error.");
            end
        end

        // Report completion of testbench
        $display("Testbench completed");
        done_flag = 1;
        $finish;
    end

    // Dump signal activity for waveform viewing
    initial begin
        $dumpfile("../../sim/waveforms/fourToOne_mux_tb.vcd");
        $dumpvars(0, fourToOne_mux_tb);
    end

    // Continuously monitor signals during simulation
    initial begin
        $monitor("Monitor: %4t | sel=%b -> out=%h", $time, tb_sel, tb_out);
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