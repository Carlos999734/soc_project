`timescale 1ns/1ps
import soc_pkg::*; // Importing the package that defines the data_t type and other shared definitions

// ============================================================================
//  Project    : SoC project
//  Module     : register
//  Author     : Carlos Diaz
//  Description: N-bit register module implemented as an array of D flip-flops.
//               Each bit is stored in its own DFF. The output updates on the
//               rising edge of the clock.
//  ============================================================================

module register(
    input  data_t d,    // Data input
    input  logic clk,   // Clock input
    output data_t out   // Data output (registered value)
);

genvar i; // Loop variable for generate block

// Generate N flip-flops, one per bit of the data_t vector
generate
    for (i = 0; i < DATA_WIDTH; i++) begin : dff_chain
        dff dff_inst (
            .clk(clk),    // Clock signal
            .d(d[i]),     // Connect bit i of input
            .out(out[i])  // Connect bit i of output
        );
    end
endgenerate

endmodule
// End of register module