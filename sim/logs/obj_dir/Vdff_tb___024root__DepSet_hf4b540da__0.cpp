// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdff_tb.h for the primary calling header

#include "Vdff_tb__pch.h"
#include "Vdff_tb__Syms.h"
#include "Vdff_tb___024root.h"

VL_INLINE_OPT VlCoroutine Vdff_tb___024root___eval_initial__TOP__Vtiming__0(Vdff_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdff_tb___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vdff_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ dff_tb__DOT__prev_out;
    dff_tb__DOT__prev_out = 0;
    IData/*31:0*/ dff_tb__DOT__unnamedblk1__DOT__i;
    dff_tb__DOT__unnamedblk1__DOT__i = 0;
    // Body
    VL_WRITEF_NX("Starting testbench for dff\n",0);
    vlSelfRef.dff_tb__DOT__tb_d = 0U;
    dff_tb__DOT__prev_out = 0U;
    co_await vlSelfRef.__VtrigSched_h5bbf41ea__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge dff_tb.tb_clk)", 
                                                         "../../src/pkg/../../tb/dff_tb.sv", 
                                                         49);
    co_await vlSelfRef.__VtrigSched_h5bbf41ea__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge dff_tb.tb_clk)", 
                                                         "../../src/pkg/../../tb/dff_tb.sv", 
                                                         50);
    co_await vlSelfRef.__VtrigSched_h5bbf41ea__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge dff_tb.tb_clk)", 
                                                         "../../src/pkg/../../tb/dff_tb.sv", 
                                                         51);
    dff_tb__DOT__unnamedblk1__DOT__i = 0U;
    while (VL_GTS_III(32, 0x64U, dff_tb__DOT__unnamedblk1__DOT__i)) {
        if (VL_LTS_III(32, 0U, dff_tb__DOT__unnamedblk1__DOT__i)) {
            if (VL_UNLIKELY((((IData)(vlSelfRef.dff_tb__DOT__tb_out) 
                              != (IData)(dff_tb__DOT__prev_out))))) {
                VL_WRITEF_NX("[%0t] %%Error: dff_tb.sv:57: Assertion failed in %Ndff_tb.unnamedblk1: FAIL: d=%b clk=%b \342\206\222 out=%b (expected out=%b)\n",0,
                             64,VL_TIME_UNITED_Q(1000),
                             -9,vlSymsp->name(),1,(IData)(vlSelfRef.dff_tb__DOT__tb_d),
                             1,vlSelfRef.dff_tb__DOT__tb_clk,
                             1,(IData)(vlSelfRef.dff_tb__DOT__tb_out),
                             1,dff_tb__DOT__prev_out);
                VL_STOP_MT("../../src/pkg/../../tb/dff_tb.sv", 57, "");
                vlSelfRef.dff_tb__DOT__fail_count = 
                    ((IData)(1U) + vlSelfRef.dff_tb__DOT__fail_count);
            } else {
                vlSelfRef.dff_tb__DOT__pass_count = 
                    ((IData)(1U) + vlSelfRef.dff_tb__DOT__pass_count);
            }
        }
        co_await vlSelfRef.__VtrigSched_h5bbf41ab__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge dff_tb.tb_clk)", 
                                                             "../../src/pkg/../../tb/dff_tb.sv", 
                                                             66);
        vlSelfRef.dff_tb__DOT__tb_d = (1U & VL_URANDOM_RANGE_I(0U, 1U));
        co_await vlSelfRef.__VtrigSched_h5bbf41ea__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge dff_tb.tb_clk)", 
                                                             "../../src/pkg/../../tb/dff_tb.sv", 
                                                             70);
        dff_tb__DOT__prev_out = vlSelfRef.dff_tb__DOT__tb_d;
        dff_tb__DOT__unnamedblk1__DOT__i = ((IData)(1U) 
                                            + dff_tb__DOT__unnamedblk1__DOT__i);
    }
    VL_WRITEF_NX("Testbench complete: %0d passed, %0d failed\n",0,
                 32,vlSelfRef.dff_tb__DOT__pass_count,
                 32,vlSelfRef.dff_tb__DOT__fail_count);
    VL_FINISH_MT("../../src/pkg/../../tb/dff_tb.sv", 75, "");
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdff_tb___024root___dump_triggers__act(Vdff_tb___024root* vlSelf);
#endif  // VL_DEBUG

void Vdff_tb___024root___eval_triggers__act(Vdff_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdff_tb___024root___eval_triggers__act\n"); );
    Vdff_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.setBit(0U, ((IData)(vlSelfRef.dff_tb__DOT__tb_clk) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__dff_tb__DOT__tb_clk__0))));
    vlSelfRef.__VactTriggered.setBit(1U, ((~ (IData)(vlSelfRef.dff_tb__DOT__tb_clk)) 
                                          & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__dff_tb__DOT__tb_clk__0)));
    vlSelfRef.__VactTriggered.setBit(2U, vlSelfRef.__VdlySched.awaitingCurrentTime());
    vlSelfRef.__Vtrigprevexpr___TOP__dff_tb__DOT__tb_clk__0 
        = vlSelfRef.dff_tb__DOT__tb_clk;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vdff_tb___024root___dump_triggers__act(vlSelf);
    }
#endif
}
