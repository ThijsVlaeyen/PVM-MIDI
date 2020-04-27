#include "midi.h"
#include "io/endianness.h"
#include "io/read.h"
#include "io/vli.h"

void midi::read_chunk_header(std::istream& in, midi::CHUNK_HEADER* ch)
{
	io::read_to(in, ch);
	io::switch_endianness(&ch->size);
}

std::string midi::header_id(const midi::CHUNK_HEADER& ch)
{
	return std::string(ch.id, sizeof(ch.id));
}

void midi::read_mthd(std::istream& in, midi::MTHD* mthd)
{
	io::read_to(in, mthd);
	io::switch_endianness(&mthd->header.size);
	io::switch_endianness(&mthd->type);
	io::switch_endianness(&mthd->ntracks);
	io::switch_endianness(&mthd->division);
}

bool midi::is_sysex_event(uint8_t byte)
{
	return byte == 0xF0 || byte == 0xF7;
}

bool midi::is_meta_event(uint8_t byte)
{
	return byte == 0xFF;
}

bool midi::is_midi_event(uint8_t byte)
{
	uint8_t event_type = extract_midi_event_type(byte);
	return event_type >= midi::midi_event::note_off && event_type <= midi::midi_event::pitch_wheel_change;
}

bool midi::is_running_status(uint8_t byte)
{
	return !(byte >> 7);
}

uint8_t midi::extract_midi_event_type(uint8_t status)
{
	return (status >> 4);
}

midi::Channel midi::extract_midi_event_channel(uint8_t status)
{
	return midi::Channel((status & 15));
}

bool midi::is_note_off(uint8_t status)
{
	return status == midi::midi_event::note_off;
}

bool midi::is_note_on(uint8_t status)
{
	return status == midi::midi_event::note_on;
}

bool midi::is_polyphonic_key_pressure(uint8_t status)
{
	return status == midi::midi_event::polyphonic_key_pressure;
}

bool midi::is_control_change(uint8_t status)
{
	return status == midi::midi_event::control_change;
}

bool midi::is_program_change(uint8_t status)
{
	return status == midi::midi_event::program_change;
}

bool midi::is_channel_pressure(uint8_t status)
{
	return status == midi::midi_event::channel_pressure;
}

bool midi::is_pitch_wheel_change(uint8_t status)
{
	return status == midi::midi_event::pitch_wheel_change;
}