//// Incorporates work from javidx9 (OneLoneCoder.com) under OLC-3 license
#pragma once
#include <cstdint>
#include "fra6502.h"
#include <array>
class Bus
{
public:
	Bus();
	~Bus();

public: //devices
	fra6502 cpu;

	std::array<uint8_t, 64 * 1024> ram;

public:
	void write(uint16_t addr, uint8_t data);
	uint8_t read(uint16_t addr, bool bReadOnly = false);

};

