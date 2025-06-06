// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vdff_tb.h for the primary calling header

#ifndef VERILATED_VDFF_TB___024UNIT_H_
#define VERILATED_VDFF_TB___024UNIT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vdff_tb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vdff_tb___024unit final : public VerilatedModule {
  public:

    // INTERNAL VARIABLES
    Vdff_tb__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vdff_tb___024unit(Vdff_tb__Syms* symsp, const char* v__name);
    ~Vdff_tb___024unit();
    VL_UNCOPYABLE(Vdff_tb___024unit);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
