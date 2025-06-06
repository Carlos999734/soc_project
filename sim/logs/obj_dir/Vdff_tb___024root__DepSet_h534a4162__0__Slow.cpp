// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdff_tb.h for the primary calling header

#include "Vdff_tb__pch.h"
#include "Vdff_tb___024root.h"

VL_ATTR_COLD void Vdff_tb___024root___eval_static__TOP(Vdff_tb___024root* vlSelf);

VL_ATTR_COLD void Vdff_tb___024root___eval_static(Vdff_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdff_tb___024root___eval_static\n"); );
    Vdff_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vdff_tb___024root___eval_static__TOP(vlSelf);
    vlSelfRef.__Vtrigprevexpr___TOP__dff_tb__DOT__tb_clk__0 = 0U;
}

VL_ATTR_COLD void Vdff_tb___024root___eval_static__TOP(Vdff_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdff_tb___024root___eval_static__TOP\n"); );
    Vdff_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.dff_tb__DOT__pass_count = 0U;
    vlSelfRef.dff_tb__DOT__fail_count = 0U;
    vlSelfRef.dff_tb__DOT__tb_clk = 0U;
}

VL_ATTR_COLD void Vdff_tb___024root___eval_final(Vdff_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdff_tb___024root___eval_final\n"); );
    Vdff_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vdff_tb___024root___eval_settle(Vdff_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdff_tb___024root___eval_settle\n"); );
    Vdff_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdff_tb___024root___dump_triggers__act(Vdff_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdff_tb___024root___dump_triggers__act\n"); );
    Vdff_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge dff_tb.tb_clk)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(negedge dff_tb.tb_clk)\n");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdff_tb___024root___dump_triggers__nba(Vdff_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdff_tb___024root___dump_triggers__nba\n"); );
    Vdff_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge dff_tb.tb_clk)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(negedge dff_tb.tb_clk)\n");
    }
    if ((4ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vdff_tb___024root___ctor_var_reset(Vdff_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdff_tb___024root___ctor_var_reset\n"); );
    Vdff_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->dff_tb__DOT__tb_d = VL_RAND_RESET_I(1);
    vlSelf->dff_tb__DOT__tb_out = VL_RAND_RESET_I(1);
    vlSelf->dff_tb__DOT__pass_count = 0;
    vlSelf->dff_tb__DOT__fail_count = 0;
    vlSelf->dff_tb__DOT__tb_clk = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__dff_tb__DOT__tb_clk__0 = VL_RAND_RESET_I(1);
}
