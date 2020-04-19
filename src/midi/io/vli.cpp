#include "vli.h"
#include "read.h"

uint64_t io::read_variable_length_integer(std::istream& in)
{
	uint64_t out = 0;

	uint8_t i;
	do {
		i = read<uint8_t>(in);
		out = (out << 7) | (uint64_t)(i & 127);
	} while (i > 127);

	return out;
}