## 🚀 Typical Workflow (Stage 2 → Stage 4)

### Automated Run with run_sim.sh

You can now automate the full flow using `/sim/scripts/run_sim.sh`.

This uses Verilator's `--binary` flow with `--top-module` to correctly select your testbench module.

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
```

This will:

✅ Compile the testbench using `--binary --top-module <tb>`  
✅ Run it and save logs to `/sim/logs/`  
✅ Save waveforms to `/sim/waveforms/`  
✅ Automatically open GTKWave  

> ⚠️ **Important:**  
> Your `$dumpfile(...)` in each testbench must match this convention:  
> ```systemverilog
> $dumpfile("sim/waveforms/<your_testbench>.vcd");
> ```  
> Otherwise the script will not find your VCD.

---

### Manual Verilator Run (backup method - now outdated)

This was the old flow using `--cc --exe --build`, which does not work with pure Verilog testbenches.

```bash
# Navigate to project root
cd "/Users/carlos/Desktop/soc_project"

# Example for comparator_tb:

verilator -sv --cc --exe --build \
    -Wall -Wno-fatal \
    -I./src/pkg \
    ./src/pkg/soc_pkg.sv \
    ./src/modules/*.sv \
    ./tb/comparator_tb.sv \
    -o sim_build/comparator_tb

# Run the compiled testbench
./sim_build/comparator_tb > ./sim/logs/comparator_tb.log

# Open waveform (if $dumpfile points to sim/waveforms/)
gtkwave ./sim/waveforms/comparator.vcd
```

---

### Build & Run Any Module

With the new project structure, source files are now organized as:

```
/src/pkg/               # Project package (soc_pkg.sv)
/src/modules/           # Design modules
/tb/                    # Testbenches
/sim/scripts/           # Run scripts
/sim/waveforms/         # Waveform outputs
/sim/logs/              # Simulation logs
```

### Notes:

✅ You can run either automated or manual flow  
✅ Automated flow is now the preferred one (correct --binary flow for Verilog TBs)  
✅ You can replace `dff_tb` with any testbench  
✅ All VCDs should point to `/sim/waveforms/`  
✅ Logs will be in `/sim/logs/`  
✅ Run all from project root (`soc_project`)

### Future (optional):

You can further automate this using `/sim/scripts/run_sim.sh`.

```
./sim/scripts/run_sim.sh dff_tb
./sim/scripts/run_sim.sh comparator_tb
```

---
