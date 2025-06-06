// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdff_tb.h for the primary calling header

#include "Vdff_tb__pch.h"
#include "Vdff_tb__Syms.h"
#include "Vdff_tb___024root.h"

void Vdff_tb___024root___ctor_var_reset(Vdff_tb___024root* vlSelf);

Vdff_tb___024root::Vdff_tb___024root(Vdff_tb__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __VdlySched{*symsp->_vm_contextp__}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vdff_tb___024root___ctor_var_reset(this);
}

void Vdff_tb___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vdff_tb___024root::~Vdff_tb___024root() {
}
