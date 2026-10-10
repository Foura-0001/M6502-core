# MOS 6502 Emulator

A basic C++ emulator for the 8-bit MOS Technology 6502 microprocessor.

## Overview

* Implements 56 legal 6502 instructions across 12 addressing modes.
* **Validates 100% against Klaus Dormann’s 6502 functional test suite**, including full BCD (decimal mode) arithmetic for `ADC` and `SBC`.
* Cycle-counted execution with branch and page-crossing penalty tracking.
* Decoupled 64 KB memory bus interface.
* Emulates `RESET`, `IRQ`, and `NMI` hardware interrupt sequences.

## Validation & Performance

* **Correctness:** The harness executes the full Dormann test binary and successfully halts at the target success trap (`$3469`).
* **Throughput:** Benchmarks at ~640 MHz-equivalent execution speed on an x86 host in a Release build (~640x real hardware speed).

## Files

* `Bus.h` / `Bus.cpp` — 64 KB RAM and memory read/write routing.
* `fra6502.h` / `fra6502.cpp` — CPU registers, flag logic, and instruction dispatch.
* `main.cpp` — Test runner, benchmark harness, and clock loop.
* `6502_functional_test.bin` — Klaus Dormann's compiled test image.

## How to Build

1. Open the project in Visual Studio 2019/2022 (C++17 or newer).
2. Set configuration to **Release / x64**.
3. Press `Ctrl + F5` to compile and run the benchmark.

## License & Credits

* This code incorporates work from javidx9 (OneLoneCoder.com).
* Hardware specifications and reference material from [NESdev Wiki](https://www.nesdev.org/wiki/Nesdev_Wiki).
* Functional validation powered by [Klaus Dormann's 6502 Test Suite](https://github.com/Klaus2m5/6502_65C02_functional_tests).
