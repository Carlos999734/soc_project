# SoC Project - Simon Says CPU Core

## Project Description

This project is a **System-on-Chip (SoC) design** and learning project with the goal of building a **custom CPU core** and integrating it into a full SoC system.  
The SoC will ultimately be used to implement a **Simon Says game on a physical PCB**.

The project is being built step-by-step to follow professional SoC design principles, with a focus on:

- Reusable modules
- Clean project structure
- Readable and scalable code
- Verification and test-driven development

---

## Current Features (Stage 2)

✅ **Reusable parameterized modules:**

- `halfadder`  
- `comparator`  
- `fourToOne_mux`  
- `highpriority_encoder`  
- `ripplecarry_adder`  
- `dff`

✅ **Testbenches** implemented and verified for all modules.

✅ **Project-wide `soc_pkg.sv`** package for:

- `DATA_WIDTH` parameterization
- Global typedefs
- Shared `compare` function

✅ **Clean project folder structure**:

- `/src` → source modules and package
- `/tb` → testbenches
- `/sim` → simulation scripts, waveforms, logs
- `/docs` → project documentation (this file)

---

## Project Roadmap / Future Plans

### Stage 3 - CPU Core Implementation

- Design ALU
- Design Register File
- Design Control Unit and FSM
- Implement top-level CPU core
- Write CPU-level testbench

### Stage 4 - SoC System

- Add RAM and ROM modules
- Add I/O peripherals for Simon Says game
- Implement memory-mapped bus
- Integrate CPU + RAM + peripherals into SoC top-level

### Stage 5 - FPGA Synthesis

- Add synthesis constraints
- Synthesize onto FPGA development board
- Debug and test hardware implementation

### Stage 6 - PCB Integration

- Design custom PCB with buttons, LEDs
- Integrate SoC into Simon Says game board
- Finalize project

---

## Project Folder Structure & Navigation

```plaintext
/soc_project
│
├── /src/                # Source code
│   ├── /modules/        # Reusable modules
│   └── /pkg/            # Project-wide package (soc_pkg.sv)
│
├── /tb/                 # Testbenches for modules
│
├── /sim/                # Simulation artifacts
│   ├── /scripts/        # Run scripts (ex: run_sim.sh)
│   ├── /waveforms/      # Waveform outputs (ex: VCD files)
│   ├── /logs/           # Simulation logs
│   └── simREADME.md     # Explanation of /sim folder
│
├── /docs/               # Project documentation
│   └── README.md        # Project overview (this file)
│
└── README.md            # Optional: top-level readme (could link to /docs/README.md)
```

---

## How to Navigate the Project

1. To explore implemented modules → go to `/src/modules/`
2. To see the package definitions → go to `/src/pkg/soc_pkg.sv`
3. To run testbenches → use `/sim/scripts/` (run_sim.sh planned)
4. To view simulation results → look in `/sim/waveforms/`
5. To read project documentation → `/docs/`

---

## Author

**Carlos Diaz**  
SoC Design Project - Simon Says CPU Core

---

*This README will be updated as the project progresses through each stage.*
