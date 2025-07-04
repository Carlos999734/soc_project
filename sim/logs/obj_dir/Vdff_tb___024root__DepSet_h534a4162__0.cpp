// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdff_tb.h for the primary calling header

#include "Vdff_tb__pch.h"
#include "Vdff_tb___024root.h"

VL_ATTR_COLD void Vdff_tb___024root___eval_initial__TOP(Vdff_tb___024root* vlSelf);
VlCoroutine Vdff_tb___024root___eval_initial__TOP__Vtiming__0(Vdff_tb___024root* vlSelf);
VlCoroutine Vdff_tb___024root___eval_initial__TOP__Vtiming__1(Vdff_tb___024root* vlSelf);
VlCoroutine Vdff_tb___024root___eval_initial__TOP__Vtiming__2(Vdff_tb___024root* vlSelf);

void Vdff_tb___024root___eval_initial(Vdff_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdff_tb___024root___eval_initial\n"); );
    Vdff_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vdff_tb___024root___eval_initial__TOP(vlSelf);
    Vdff_tb___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vdff_tb___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    Vdff_tb___024root___eval_initial__TOP__Vtiming__2(vlSelf);
}

VL_INLINE_OPT VlCoroutine Vdff_tb___024root___eval_initial__TOP__Vtiming__1(Vdff_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdff_tb___024root___eval_initial__TOP__Vtiming__1\n"); );
    Vdff_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x4c4b40ULL, 
                                         nullptr, "../../src/pkg/../../tb/dff_tb.sv", 
                                         91);
    VL_FINISH_MT("../../src/pkg/../../tb/dff_tb.sv", 92, "");
}

VL_INLINE_OPT VlCoroutine Vdff_tb___024root___eval_initial__TOP__Vtiming__2(Vdff_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdff_tb___024root___eval_initial__TOP__Vtiming__2\n"); );
    Vdff_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (1U) {
        co_await vlSelfRef.__VdlySched.delay(0x1388ULL, 
                                             nullptr, 
                                             "../../src/pkg/../../tb/dff_tb.sv", 
                                             25);
        vlSelfRef.dff_tb__DOT__tb_clk = (1U & (~ (IData)(vlSelfRef.dff_tb__DOT__tb_clk)));
    }
}

void Vdff_tb___024root___eval_act(Vdff_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdff_tb___024root___eval_act\n"); );
    Vdff_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vdff_tb___024root___nba_sequent__TOP__0(Vdff_tb___024root* vlSelf);

void Vdff_tb___024root___eval_nba(Vdff_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdff_tb___024root___eval_nba\n"); );
    Vdff_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vdff_tb___024root___nba_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vdff_tb___024root___nba_sequent__TOP__0(Vdff_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdff_tb___024root___nba_sequent__TOP__0\n"); );
    Vdff_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_WRITEF_NX("Time %0t: d=%b clk=%b \342\206\222 out=%b\n",0,
                 64,VL_TIME_UNITED_Q(1000),-9,1,(IData)(vlSelfRef.dff_tb__DOT__tb_d),
                 1,vlSelfRef.dff_tb__DOT__tb_clk,1,
                 (IData)(vlSelfRef.dff_tb__DOT__tb_out));
    vlSelfRef.dff_tb__DOT__tb_out = vlSelfRef.dff_tb__DOT__tb_d;
}

void Vdff_tb___024root___timing_commit(Vdff_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdff_tb___024root___timing_commit\n"); );
    Vdff_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((! (1ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_h5bbf41ea__0.commit(
                                                   "@(posedge dff_tb.tb_clk)");
    }
    if ((! (2ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_h5bbf41ab__0.commit(
                                                   "@(negedge dff_tb.tb_clk)");
    }
}

void Vdff_tb___024root___timing_resume(Vdff_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdff_tb___024root___timing_resume\n"); );
    Vdff_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_h5bbf41ea__0.resume(
                                                   "@(posedge dff_tb.tb_clk)");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_h5bbf41ab__0.resume(
                                                   "@(negedge dff_tb.tb_clk)");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vdff_tb___024root___eval_triggers__act(Vdff_tb___024root* vlSelf);

bool Vdff_tb___024root___eval_phase__act(Vdff_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdff_tb___024root___eval_phase__act\n"); );
    Vdff_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<3> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vdff_tb___024root___eval_triggers__act(vlSelf);
    Vdff_tb___024root___timing_commit(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vdff_tb___024root___timing_resume(vlSelf);
        Vdff_tb___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vdff_tb___024root___eval_phase__nba(Vdff_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdff_tb___024root___eval_phase__nba\n"); );
    Vdff_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vdff_tb___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdff_tb___024root___dump_triggers__nba(Vdff_tb___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vdff_tb___024root___dump_triggers__act(Vdff_tb___024root* vlSelf);
#endif  // VL_DEBUG

void Vdff_tb___024root___eval(Vdff_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdff_tb___024root___eval\n"); );
    Vdff_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vdff_tb___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("../../src/pkg/../../tb/dff_tb.sv", 14, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vdff_tb___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("../../src/pkg/../../tb/dff_tb.sv", 14, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vdff_tb___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vdff_tb___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vdff_tb___024root___eval_debug_assertions(Vdff_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdff_tb___024root___eval_debug_assertions\n"); );
    Vdff_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
