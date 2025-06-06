//====================================================
// Module: fourToOne_mux
// Project: SoC Project
// File: fourToOne_mux.sv
// Author: Carlos
// Description:
//   4-to-1 Multiplexer module.
//   Selects one of four data_t inputs based on a 2-bit select signal.
//====================================================
`timescale 1ns/1ps
import soc_pkg::*; // Importing package for project-wide consistency

// 4-to-1 Multiplexer module
// Selects one of four data_t inputs based on 2-bit select signal
module fourToOne_mux(
    input  data_t D0,    // Input 0
    input  data_t D1,    // Input 1
    input  data_t D2,    // Input 2
    input  data_t D3,    // Input 3
    input  logic [1:0] sel, // Select signal
    output data_t out    // Selected output
);

    // Combinational logic: select output based on sel
    always_comb begin
        case(sel)
            2'b00:  out = D0; // Select input 0
            2'b01:  out = D1; // Select input 1
            2'b10:  out = D2; // Select input 2
            2'b11:  out = D3; // Select input 3
            default: out = '0; // Default to zero (safe fallback)
        endcase
    end

endmodule // End of 4-to-1 Multiplexer module
