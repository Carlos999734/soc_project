// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdff_tb.h for the primary calling header

#include "Vdff_tb__pch.h"
#include "Vdff_tb__Syms.h"
#include "Vdff_tb___024unit.h"

void Vdff_tb___024unit___ctor_var_reset(Vdff_tb___024unit* vlSelf);

Vdff_tb___024unit::Vdff_tb___024unit(Vdff_tb__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vdff_tb___024unit___ctor_var_reset(this);
}

void Vdff_tb___024unit::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vdff_tb___024unit::~Vdff_tb___024unit() {
}
