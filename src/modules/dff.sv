//====================================================
// Module: dff
// Project: SoC Project
// File: dff.sv
// Author: Carlos
// Description:
//   D Flip-Flop module.
//   On the rising edge of clk, output 'out' is updated to the value of input 'd'.
//====================================================
`timescale 1ns/1ps
import soc_pkg::*; // Importing package for project-wide consistency

// D Flip-Flop module
// On the rising edge of clk, output 'out' is updated to the value of input 'd'
module dff(
    input  logic d,      // Data input (1 bit)
    input  logic clk,    // Clock input
    output logic out     // Output (stored value, 1 bit)
);

    // Sequential logic: on rising edge of clk, capture the input 'd'
    always_ff @(posedge clk) begin
        out <= d; // Non-blocking assignment for proper timing behavior
    end

endmodule // End of D Flip-Flop module
