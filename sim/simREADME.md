

# Simulation Folder (`/sim`)

This folder contains all files related to running simulations for the SoC Project.

## Current Structure

- `/scripts/`  
  Contains run scripts and simulator configuration files.  
  Example: `run_sim.sh`, `compile.f`, `vsim.do`, etc.

- `/waveforms/`  
  Stores output waveform files from simulation runs.  
  Example: `.vcd`, `.fsdb`, or other waveform formats.

- `/logs/`  
  Stores console output and simulation logs.  
  Example: `sim.log`, `compile.log`.

## How to Use

1. Place your run scripts in `/scripts/`.
2. Run simulations using `run_sim.sh` or other tools.
3. Generated waveforms go into `/waveforms/`.
4. Logs go into `/logs/`.

## Future Plans

As the project grows, we may add:

- `/models/`  
  For verification models and behavioral reference models.

- `/config/`  
  For simulation configuration files, defines, macros, and environment files.

- `/tb/`  
  Optionally organize testbenches here if the number of testbenches grows large.

- Regression testing scripts and CI integration.

- Simulator-specific setups (ModelSim, Verilator, Synopsys VCS, etc.).

This structure helps keep simulation assets organized and separate from source files.