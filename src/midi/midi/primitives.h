#ifndef PRIMITIVES_H
#define PRIMITIVES_H

#include <cstdint>
#include "util/tagged.h"

namespace midi
{
	struct __declspec(empty_bases)Channel : show_value<Channel, int>, equality<Channel>, tagged<uint8_t, Channel> { using tagged::tagged; };
	struct __declspec(empty_bases)Instrument : show_value<Instrument, int>, equality<Instrument>, tagged<uint8_t, Instrument> { using tagged::tagged; };

}

#endif