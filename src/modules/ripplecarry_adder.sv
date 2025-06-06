//====================================================
// Module: ripple_carry_adder
// Project: SoC Project
// File: ripple_carry_adder.sv
// Author: Carlos Diaz
// Description:
//   Ripple-Carry Adder (8-bit) module.
//   Adds two DATA_WIDTH-wide unsigned numbers and outputs sum and carry-out.
//====================================================

`timescale 1ns / 1ps

import soc_pkg::*;

module ripplecarry_adder(
    input  data_t a,        // First operand
    input  data_t b,        // Second operand
    output data_t sum,      // Sum output
    output logic carryOut   // Carry out bit
);
    // Perform addition of two DATA_WIDTH-wide inputs.
    // The carryOut is the overflow bit beyond DATA_WIDTH.
    assign {carryOut, sum} = a + b;
endmodule
