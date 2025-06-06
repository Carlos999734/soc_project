// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VDFF_TB__SYMS_H_
#define VERILATED_VDFF_TB__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vdff_tb.h"

// INCLUDE MODULE CLASSES
#include "Vdff_tb___024root.h"
#include "Vdff_tb___024unit.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vdff_tb__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vdff_tb* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vdff_tb___024root              TOP;

    // CONSTRUCTORS
    Vdff_tb__Syms(VerilatedContext* contextp, const char* namep, Vdff_tb* modelp);
    ~Vdff_tb__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
