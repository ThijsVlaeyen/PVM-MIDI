#include "endianness.h"

void io::switch_endianness(uint16_t* n)
{
	*n = (*n << 8) | (*n >> 8);
}

void io::switch_endianness(uint32_t* n)
{
	//1234
	*n = ((*n << 8) & 0xFF00FF00) | ((*n >> 8) & 0xFF00FF); //2143
	*n = (*n << 16) | (*n >> 16); //4321
}

void io::switch_endianness(uint64_t* n)
{
	//12345678
	*n = ((*n << 8) & 0xFF00FF00FF00FF00) | ((*n >> 8) & 0x00FF00FF00FF00FF); //21436587
	*n = ((*n << 16) & 0xFFFF0000FFFF0000) | ((*n >> 16) & 0x0000FFFF0000FFFF); //43218765
	*n = (*n << 32) | (*n >> 32); //87654321
}