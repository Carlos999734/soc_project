

# SoC Project — Git Repository

## Project Description

This is a custom System-on-Chip (SoC) design project, focusing on:

- Designing and simulating a simple CPU core and reusable logic components.
- Building a professional SystemVerilog codebase.
- Verifying all modules with automated testbenches.
- Developing a complete workflow from RTL to simulation and waveform analysis.

Current stage: **Stage 2 — SystemVerilog Fundamentals + Testbench Development**  
Next stage: **Stage 3 — CPU Integration and System Design**

---

## How to Run Simulations

We use **Icarus Verilog + VVP** for simulation. The project includes an automated run script:

```bash
cd /Users/carlos/Desktop/soc_project/sim/scripts
./run_sim.sh <testbench_name>
```

Example:

```bash
./run_sim.sh dff_tb
./run_sim.sh comparator_tb
./run_sim.sh ripplecarry_adder_tb
./run_sim.sh fourToOne_mux_tb
./run_sim.sh highpriority_encoder_tb
./run_sim.sh halfadder_tb
```

This will:

✅ Compile the testbench  
✅ Run simulation  
✅ Generate VCD waveform in `/sim/waveforms/`  
✅ Open GTKWave  

---

## Project Structure

```
/src/pkg/               # Project package (soc_pkg.sv)
/src/modules/           # Design modules
/tb/                    # Testbenches
/sim/scripts/           # Run scripts (run_sim.sh)
/sim/waveforms/         # Waveform outputs (.vcd)
/sim/build/             # vvp binaries
/sim/logs/              # (optional) Simulation logs
/docs/                  # Documentation (workflow.md, testbenchREADME.md, gitREADME.md)
.gitignore              # Git ignore rules
```

---

## Git Workflow

### Initial Setup

```bash
git init
git add .
git commit -m "Initial commit — Stage 2 project"
```

### Git Best Practices

✅ Commit after each module or major testbench change  
✅ Use meaningful commit messages  
✅ Never commit `/sim/build/`, `/sim/waveforms/`, or `/sim/logs/` (already handled by `.gitignore`)  
✅ Keep `/docs/` up to date  
✅ Tag major milestones:

```bash
git tag stage-2-complete
git push --tags
```

---

## Why Use Git

- Full version history
- Ability to roll back changes
- Easier to track testbench improvements
- Foundation for future GitHub publication
- Critical for professional SoC and verification work

---

## Next Steps

✅ Finalize Stage 2  
✅ Begin Stage 3 — CPU Integration  
✅ Add more testbenches  
✅ Possibly move to Verilator / commercial simulators  
✅ Add Makefile or CI flow for full automation  
✅ Publish to GitHub when ready

---

### Great job bringing this project to a professional level — this Git workflow will serve you very well going forward!