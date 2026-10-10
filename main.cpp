#include <iostream>
#include "Bus.h"
#include "fra6502.h"

//std::string instructions(std::string) //reads instructions as string from file.
//{
//	bool eof = false;
//}

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

	//uint16_t offset = 0x8000;
	//bus.write(offset++, 0xA9);
	//bus.write(offset++, 0x0A);
	//bus.write(offset++, 0x8D);
	//bus.write(offset++, 0x00);
	//bus.write(offset++, 0x00);

	//bus.ram[0xFFFC] = 0x00;
	//bus.ram[0xFFFD] = 0x80;

	bus.cpu.reset();

	for (int i = 0; i < 20; i++)
	{

		bus.cpu.clock();
		printeffect(bus.cpu);
	}
	std::cout << "RAM at $0000: 0x" << (int)bus.ram[0x0000] << "\n";

	return 0;
}