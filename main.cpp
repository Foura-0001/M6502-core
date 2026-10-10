#include <iostream>
#include "Bus.h"
#include "fra6502.h"
#include<chrono>
#include<fstream>
#include<vector>
#include<algorithm>

//std::string instructions(std::string) //reads instructions as string from file.
//{
//	bool eof = false;
//}
const uint16_t ITERATIONS = 100;
const uint16_t WARMUP = 4;

void static printeffect(const fra6502& cpu) //prints the results of an input to the console.
{
	std::cout << std::hex << std::uppercase;
	std::cout << "PC:           0x" << (int)cpu.pc << "\n";
	std::cout << "A register:   0x" << (int)cpu.a << "\n";
	std::cout << "X register:   0x" << (int)cpu.x << "\n";
	std::cout << "Y register:   0x" << (int)cpu.y << "\n";
	std::cout << "Status:       0x" << (int)cpu.status << "\n";
}




int main()
{
	Bus bus;
	

	//implement file reading and ram initialization 
	double counter = 0;
	//std::vector <double> MHz;

	

	for (int i = 0; i < ITERATIONS; i++) {
		
		std::ifstream f("6502_functional_test.bin", std::ios::binary);
		bool ok = f.is_open();
		if (ok == false)
		{
			std::cout << " cant open file " << '\n';
			return 1;
		}
		f.read(reinterpret_cast<char*>(bus.ram.data()), bus.ram.size());

		if (bus.ram.size() != f.gcount())
		{
			std::cout << " short read " << '\n';
			return 1;
		}

		if (!(bus.ram[0x0400] == 0xD8 && bus.ram[0x0401] == 0xA2 && bus.ram[0x0402] == 0xFF))
		{
			std::cout << "incorrect read" << '\n';
			return 1;
		}

		bus.cpu.reset();
		bus.cpu.pc = 0x0400;


		auto start = std::chrono::steady_clock::now();
		
		while (!bus.cpu.clock())
		{
			counter++;
		}
		auto end = std::chrono::steady_clock::now();
		std::chrono::duration<double> elapsed = end - start;
		if (i > WARMUP) {
			//MHz.push_back();
			std::cout << "Emulation Speed: " << (((counter / elapsed.count())) / 1'000'000.0) << " MHz at ith value \n";
		}
		
		counter = 0;
	}
	
	std::cout << std::hex
		<< "pc: 0x" << bus.cpu.pc << '\n';
	
	return 0;
}