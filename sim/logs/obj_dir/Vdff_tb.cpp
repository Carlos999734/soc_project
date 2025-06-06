// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vdff_tb__pch.h"

//============================================================
// Constructors

Vdff_tb::Vdff_tb(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vdff_tb__Syms(contextp(), _vcname__, this)}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vdff_tb::Vdff_tb(const char* _vcname__)
    : Vdff_tb(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vdff_tb::~Vdff_tb() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vdff_tb___024root___eval_debug_assertions(Vdff_tb___024root* vlSelf);
#endif  // VL_DEBUG
void Vdff_tb___024root___eval_static(Vdff_tb___024root* vlSelf);
void Vdff_tb___024root___eval_initial(Vdff_tb___024root* vlSelf);
void Vdff_tb___024root___eval_settle(Vdff_tb___024root* vlSelf);
void Vdff_tb___024root___eval(Vdff_tb___024root* vlSelf);

void Vdff_tb::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vdff_tb::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vdff_tb___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vdff_tb___024root___eval_static(&(vlSymsp->TOP));
        Vdff_tb___024root___eval_initial(&(vlSymsp->TOP));
        Vdff_tb___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vdff_tb___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vdff_tb::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty(); }

uint64_t Vdff_tb::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vdff_tb::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vdff_tb___024root___eval_final(Vdff_tb___024root* vlSelf);

VL_ATTR_COLD void Vdff_tb::final() {
    Vdff_tb___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vdff_tb::hierName() const { return vlSymsp->name(); }
const char* Vdff_tb::modelName() const { return "Vdff_tb"; }
unsigned Vdff_tb::threads() const { return 1; }
void Vdff_tb::prepareClone() const { contextp()->prepareClone(); }
void Vdff_tb::atClone() const {
    contextp()->threadPoolpOnClone();
}
