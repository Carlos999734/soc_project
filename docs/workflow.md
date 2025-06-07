## 🚀 Typical Workflow (Stage 2 → Stage 4)

### Automated Run with run_sim.sh (Current Flow)

You can now automate the full flow using `/sim/scripts/run_sim.sh`.

This runs Icarus Verilog (iverilog) → generates vvp binary → runs simulation with vvp → generates VCD → opens in GTKWave.

> ⚠️ **First time only:**  
> You need to make the script executable:  
> ```bash
> chmod +x run_sim.sh
> ```  
> After this, you can run it normally.

#### Example (copy & paste into terminal):

```bash
cd "/Users/carlos/Desktop/soc_project/sim/scripts"
./run_sim.sh dff_tb
```

Or for other testbenches:

```bash
./run_sim.sh comparator_tb
./run_sim.sh ripplecarry_adder_tb
./run_sim.sh fourToOne_mux_tb
./run_sim.sh highpriority_encoder_tb
./run_sim.sh halfadder_tb
```

This will:

✅ Compile the testbench with Icarus Verilog  
✅ Generate .vvp binary to `/sim/build/`  
✅ Run it with vvp  
✅ Save waveforms to `/sim/waveforms/`  
✅ Automatically open GTKWave  
✅ Display monitor and test results in terminal

> ⚠️ **Important:**  
> Your `$dumpfile(...)` in each testbench must match this convention:  
> ```systemverilog
> $dumpfile("../../sim/waveforms/<your_testbench>.vcd");
> ```  
> Otherwise the script will not find your VCD.

---

### Manual Icarus Verilog Run (backup method)

If needed, you can manually run:

```bash
# Navigate to project root
cd "/Users/carlos/Desktop/soc_project"

# Compile:
iverilog -g2012 -o sim/build/dff_tb \
    src/pkg/soc_pkg.sv \
    src/modules/*.sv \
    tb/dff_tb.sv

# Run:
vvp sim/build/dff_tb

# Open waveform:
gtkwave sim/waveforms/dff_tb.vcd
```

---

### Project Structure

```
/src/pkg/               # Project package (soc_pkg.sv)
/src/modules/           # Design modules
/tb/                    # Testbenches
/sim/scripts/           # Run scripts (run_sim.sh)
/sim/waveforms/         # Waveform outputs (.vcd)
/sim/build/             # vvp binaries
/sim/logs/              # (optional) Simulation logs
/docs/                  # Documentation (workflow.md, testbenchREADME.md, etc.)
```

---

### Notes:

✅ Automated flow is the preferred one  
✅ You can run any testbench — no need to modify run_sim.sh anymore (uses wildcard + soc_pkg.sv first)  
✅ All VCDs must point to `/sim/waveforms/`  
✅ Build artifacts are in `/sim/build/`  
✅ Run everything from project root or from `/sim/scripts/`

---

### Future:

- When moving to Verilator, we can reintroduce `--binary` flow and update this file again.
- We will also explore Makefiles or other build automation.

---
