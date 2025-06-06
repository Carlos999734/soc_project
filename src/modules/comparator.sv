//====================================================
// Module: comparator
// Project: SoC Project
// File: comparator.sv
// Author: Carlos
// Description:
//   Comparator module.
//   Compares two input data_t values and outputs flags indicating their relationship.
//====================================================
`timescale 1ns/1ps
import soc_pkg::*; // Importing the package that defines the data_t type and other shared definitions

// Comparator module: compares two input data_t values and outputs flags indicating their relationship
module comparator(
    input  data_t a,       // First input operand to compare
    input  data_t b,       // Second input operand to compare
    output logic equal,    // High if inputs are equal
    output logic less,     // High if a is less than b
    output logic greater   // High if a is greater than b
);

    // Moved cmp_result to module scope for cross-simulator compatibility
    logic [2:0] cmp_result;

    // Always_comb block to continuously evaluate comparison outputs based on inputs a and b
    always_comb begin
        cmp_result = soc_pkg::compare(a, b);
    end

    // Continuous assignments to outputs (safe in all simulators)
    assign equal   = cmp_result[2];  // equal flag assigned from bit 2
    assign less    = cmp_result[1];  // less flag assigned from bit 1
    assign greater = cmp_result[0];  // greater flag assigned from bit 0

endmodule // End of comparator module
