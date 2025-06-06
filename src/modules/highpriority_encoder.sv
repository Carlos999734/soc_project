//====================================================
// Module: highpriority_encoder
// Project: SoC Project
// File: highpriority_encoder.sv
// Author: Carlos Diaz
// Description:
//   High-Priority Encoder module.
//   Encodes four 1-bit inputs into a 2-bit output, giving priority to the highest-indexed active input.
//====================================================

`timescale 1ns/1ps

import soc_pkg::*;

module highpriority_encoder (
    input logic a,  // Input signal a (lowest priority)
    input logic b,  // Input signal b
    input logic c,  // Input signal c
    input logic d,  // Input signal d (highest priority)
    output logic [1:0] out  // Encoded 2-bit output representing highest priority active input
);

        always_comb begin
        if (d) begin
            out = 2'b11; // Highest priority
        end else if (c) begin
            out = 2'b10; // Second highest priority
        end else if (b) begin
            out = 2'b01; // Third highest priority
        end else begin
            out = 2'b00; // Lowest priority and default case
        end
    end

endmodule
