// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdff_tb.h for the primary calling header

#include "Vdff_tb__pch.h"
#include "Vdff_tb__Syms.h"
#include "Vdff_tb___024root.h"

VL_ATTR_COLD void Vdff_tb___024root___eval_initial__TOP(Vdff_tb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdff_tb___024root___eval_initial__TOP\n"); );
    Vdff_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<6>/*191:0*/ __Vtemp_1;
    // Body
    __Vtemp_1[0U] = 0x2e766364U;
    __Vtemp_1[1U] = 0x2f646666U;
    __Vtemp_1[2U] = 0x6f726d73U;
    __Vtemp_1[3U] = 0x61766566U;
    __Vtemp_1[4U] = 0x696d2f77U;
    __Vtemp_1[5U] = 0x73U;
    vlSymsp->_vm_contextp__->dumpfile(VL_CVT_PACK_STR_NW(6, __Vtemp_1));
    VL_PRINTF_MT("-Info: ../../src/pkg/../../tb/dff_tb.sv:81: $dumpvar ignored, as Verilated without --trace\n");
}
