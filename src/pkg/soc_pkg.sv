`timescale 1ns/1ps

//====================================================
// soc_pkg.sv
// Project-wide package for SoC project
// Used by all modules in the SoC (CPU core, ALU, registers, memory, etc.)
//----------------------------------------------------
// HOW TO USE:
// import soc_pkg::*;
//----------------------------------------------------
// CURRENT STAGE: Stage 2 - building reusable modules (register, comparator, DFF, etc.)
// FUTURE STAGES: Will expand this package as the project grows
//====================================================

package soc_pkg;

    //-----------------------------------
    // Global parameters
    //-----------------------------------

    // Data bus width (change to 16, 32 later if needed)
    parameter int DATA_WIDTH = 8;

    // Address width (for RAM, ROM, register file, etc.)
    parameter int ADDR_WIDTH = 8;  // 256 addressable locations

    // Number of general-purpose CPU registers (Stage 3+)
    parameter int REG_COUNT = 8;

    // Memory size in bytes (Stage 3+)
    parameter int MEM_SIZE = 256;

    //-----------------------------------
    // Typedefs
    //-----------------------------------

    // Typedef for data buses
    typedef logic [DATA_WIDTH-1:0] data_t;

    // Typedef for address buses
    typedef logic [ADDR_WIDTH-1:0] addr_t;

    // Typedef for register index (if you implement register file)
    typedef logic [$clog2(REG_COUNT)-1:0] reg_index_t;

    //-----------------------------------
    // Global Functions
    //-----------------------------------

    // Compare two data_t values
    // Returns [equal, less, greater] in 3-bit vector
    function automatic logic [2:0] compare(input data_t x, input data_t y);
        logic [2:0] result;
        if (x == y) begin
            result = 3'b100; // equal = 1
        end else if (x > y) begin
            result = 3'b001; // greater = 1
        end else begin
            result = 3'b010; // less = 1
        end
        return result;
    endfunction

    //-----------------------------------
    // ALU operations (placeholder - Stage 3+)
    //-----------------------------------

    typedef enum logic [3:0] {
        ALU_ADD  = 4'b0000,
        ALU_SUB  = 4'b0001,
        ALU_AND  = 4'b0010,
        ALU_OR   = 4'b0011,
        ALU_XOR  = 4'b0100,
        ALU_PASS = 4'b0101
        // Add more as needed
    } alu_op_t;

    //-----------------------------------
    // Instruction opcodes (placeholder - Stage 3+)
    //-----------------------------------

    typedef enum logic [7:0] {
        OP_NOP   = 8'h00,
        OP_LOAD  = 8'h01,
        OP_STORE = 8'h02,
        OP_ADD   = 8'h03,
        OP_SUB   = 8'h04,
        OP_JUMP  = 8'h05
        // Add more instructions here
    } opcode_t;

    //-----------------------------------
    // Status flags (placeholder - Stage 3+)
    //-----------------------------------

    typedef struct packed {
        logic zero;
        logic carry;
        logic overflow;
        logic negative;
    } status_flags_t;

    //-----------------------------------
    // Future expansion (Stages 4+)
    //-----------------------------------
    // - Timer constants
    // - Interrupt vectors
    // - Peripheral addresses
    // - Special function registers
    // - SoC version number
    // - Build-time defines
    // - Debug configuration
    // - Simulation control flags
    //-----------------------------------

endpackage : soc_pkg

