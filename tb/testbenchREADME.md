

# Testbench README — SoC Project

## Purpose

This document explains:
- Why specific changes were made to our testbenches to work reliably with Icarus Verilog 12.0.
- The general testbench design philosophy we are following in this project.
- Common pitfalls and best practices to maintain a professional verification flow.

---

## Why did we modify our testbenches?

### 1️⃣ Imported typedefs (data_t)

**Problem:**  
Icarus Verilog 12.0 does not correctly parse `typedef` imported from a package when declared inside an `initial` block.

**Fix:**  
We moved all `data_t` declarations (such as `ref_a`, `ref_b`, `ref_out`, etc.) to **module scope** — at the top of the testbench.

---

### 2️⃣ $urandom_range slicing

**Problem:**  
Icarus Verilog 12.0 does not support bit-slicing directly on `$urandom_range`.

**Fix:**  
We now assign `$urandom_range` to an `int rand_val`, then assign the sliced result to our `data_t` variables:

```systemverilog
int rand_val;
rand_val = $urandom_range(0, 255);
tb_a = rand_val[DATA_WIDTH-1:0];
```

---

### 3️⃣ $fatal syntax

**Problem:**  
SystemVerilog requires `$fatal` to have a numeric first argument.  
Icarus Verilog will give an error if this is omitted.

**Fix:**  
We now use:

```systemverilog
$fatal(1, "Aborting on first error.");
```

---

### 4️⃣ Default case in `case` statements

**Problem:**  
Icarus Verilog 12.0 sometimes fails to parse `default:` if the `case` already covers all possible cases and the assigned signal is a vector.

**Fix:**  
- We carefully ensure that the default case uses:

```systemverilog
default: ref_out = {DATA_WIDTH{1'b0}};
```

- In cases where all possible cases are fully enumerated (such as 2-bit selects), we may safely omit the `default`.

---

### 5️⃣ Package function calls in testbenches

**Problem:**  
Icarus Verilog 12.0 does not support calling a package function inside an `initial` block when the return type is a vector.

**Fix:**  
We rewrote those references as **explicit inline logic** in the testbench, rather than calling `soc_pkg::compare()`.

---

### 6️⃣ Testbench and DUT module naming

**Best Practice:**  
We ensure:
- The **module name matches the filename** exactly.
- The testbench instantiates the DUT with the correct name.

This prevents wildcard build-order issues.

---

## Testbench Philosophy

### ✅ Professional, simulator-safe testbenches:
- Module scope declarations for typedefs.
- No $urandom_range slicing.
- Proper $fatal syntax.
- Clean use of `done_flag` and `fatal_on_error`.
- Timeout block to ensure VCD is always written.
- Consistent $dumpfile paths: `../../sim/waveforms/<testbench>.vcd`
- Consistent $monitor formatting.

---

### ✅ Why this matters:

- Icarus Verilog 12.0 is not fully SystemVerilog-compliant.
- Commercial tools (Verilator, VCS, Questa) WILL allow more flexibility — but by writing portable testbenches now, we future-proof the project.
- We also build **professional habits** for larger verification environments.

---

### ✅ Moving forward:

- New testbenches should follow this pattern:
  - `done_flag` + `fatal_on_error`
  - Proper handling of typedefs
  - Safe randomization
  - Proper $fatal
  - Consistent $dumpfile and $monitor
  - Timeout block

---

## Summary

We now have a very clean, professional testbench suite that:
✅ Works with Icarus Verilog 12.0  
✅ Will port cleanly to Verilator, VCS, or Questa  
✅ Teaches correct verification practices  

---

### Great job refining this flow — this is exactly how verification engineers build scalable, professional projects!