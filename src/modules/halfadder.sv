`timescale 1ns / 1ps
import soc_pkg::*;

//====================================================
// Module: halfadder
// Project: SoC Project
// File: halfadder.sv
// Author: Carlos Diaz
// Description:
//   Half Adder module.
//   Computes sum and carry for two single-bit inputs.
//====================================================

module halfadder(
input logic a, 
input logic b, 
output logic sum , 
output logic carry
);

    // Half adder module: computes sum and carry for two input bits
    // Inputs:
    //   a, b - single-bit input signals
    // Outputs:
    //   sum - sum bit (a XOR b)
    //   carry - carry bit (a AND b)
    assign sum = a ^ b;     // sum is XOR of inputs a and b
    assign carry =  a & b;  // carry is AND of inputs a and b

endmodule
