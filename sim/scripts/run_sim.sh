#!/bin/bash

# Simple automated iverilog simulation script
# Usage: ./run_sim.sh <testbench_name>
# Example: ./run_sim.sh dff_tb

# --- CONFIG ---

SRC_PKG="../../src/pkg"
SRC_MODULES="../../src/modules"
TB_DIR="../../tb"
BUILD_DIR="../../sim_build"
WAVEFORM_DIR="../../sim/waveforms"
LOG_DIR="../../sim/logs"

# --- ARGUMENT CHECK ---

if [ $# -ne 1 ]; then
    echo "Usage: $0 <testbench_name>"
    exit 1
fi

TB_NAME="$1"
TB_SRC="${TB_DIR}/${TB_NAME}.sv"

# --- CREATE BUILD DIRS IF NEEDED ---

mkdir -p "${BUILD_DIR}"
mkdir -p "${WAVEFORM_DIR}"
mkdir -p "${LOG_DIR}"

# --- BUILD ---

echo "Compiling ${TB_NAME} with iverilog..."
echo "iverilog version:"
iverilog -V

# Force clean of old TB binary
rm -f "${BUILD_DIR}/${TB_NAME}"

# Compile soc_pkg.sv first — this is required!
iverilog -g2012 -o "${BUILD_DIR}/${TB_NAME}" \
    "${SRC_PKG}/soc_pkg.sv" \
    "${SRC_MODULES}"/*.sv \
    "${TB_SRC}"

if [ $? -ne 0 ]; then
    echo "ERROR: Build failed!"
    exit 1
fi

# --- RUN SIMULATION ---

echo "Running ${TB_NAME} with vvp..."

vvp "${BUILD_DIR}/${TB_NAME}" > "${LOG_DIR}/${TB_NAME}.log"

if [ $? -ne 0 ]; then
    echo "ERROR: Simulation failed!"
    exit 1
fi

# --- OPEN WAVEFORM ---

# Expect VCD named as <testbench_name>.vcd
VCD_FILE="${WAVEFORM_DIR}/${TB_NAME%.sv}.vcd"
VCD_ALT="${WAVEFORM_DIR}/${TB_NAME}.vcd"

# Fallback if user hardcoded VCD name in TB
if [ -f "${VCD_FILE}" ]; then
    echo "Opening waveform: ${VCD_FILE}"
    gtkwave "${VCD_FILE}"
elif [ -f "${VCD_ALT}" ]; then
    echo "Opening waveform: ${VCD_ALT}"
    gtkwave "${VCD_ALT}"
else
    echo "WARNING: Could not find waveform VCD in ${WAVEFORM_DIR}/"
fi

echo "Done."