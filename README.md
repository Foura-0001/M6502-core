# MOS 6502 Emulator

A basic C++ emulator for the 8-bit MOS Technology 6502 microprocessor.

## Overview

* Implements 56 legal 6502 instructions across 13 addressing modes.
* Cycle-counted execution with branch and page-crossing penalty tracking.
* Decoupled 64 KB memory bus interface.
* Emulates `RESET`, `IRQ`, and `NMI` hardware interrupt sequences.

## Files

* `Bus.h` / `Bus.cpp` — 64 KB RAM and memory read/write routing.
* `fra6502.h` / `fra6502.cpp` — CPU registers, flag logic, and instruction dispatch.
* `main.cpp` — Test runner and clock loop.

## How to Build

1. Open the project in Visual Studio 2019/2022 (C++17 or newer).
2. Set configuration to **Release / x64**.
3. Press `Ctrl + F5` to compile and run.

## License & Credits

* This code incorporates work from javidx9 (OneLoneCoder.com).
* Hardware specifications and reference material from [NESdev Wiki](https://www.nesdev.org/wiki/Nesdev_Wiki).
