// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vdff_tb.h for the primary calling header

#ifndef VERILATED_VDFF_TB___024ROOT_H_
#define VERILATED_VDFF_TB___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vdff_tb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vdff_tb___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ dff_tb__DOT__tb_clk;
    CData/*0:0*/ dff_tb__DOT__tb_d;
    CData/*0:0*/ dff_tb__DOT__tb_out;
    CData/*0:0*/ __Vtrigprevexpr___TOP__dff_tb__DOT__tb_clk__0;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ dff_tb__DOT__pass_count;
    IData/*31:0*/ dff_tb__DOT__fail_count;
    IData/*31:0*/ __VactIterCount;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_h5bbf41ea__0;
    VlTriggerScheduler __VtrigSched_h5bbf41ab__0;
    VlTriggerVec<3> __VactTriggered;
    VlTriggerVec<3> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vdff_tb__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vdff_tb___024root(Vdff_tb__Syms* symsp, const char* v__name);
    ~Vdff_tb___024root();
    VL_UNCOPYABLE(Vdff_tb___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
