#pragma once
#ifndef READ_H
#define READ_H

#include <iostream>
#include "logging.h"

namespace io
{
	template<typename T>
	void read_to(std::istream& in, T* buffer, size_t n = 1)
	{
		in.read(reinterpret_cast<char*>(buffer), sizeof(T)* n);
		CHECK(!in.fail()) << __FUNCTION__ << " failed";
	}

	template<typename T, typename std::enable_if<std::is_fundamental<T>::value, T>::type * = nullptr>
	T read(std::istream& in)
	{
		T* foo = new T;
		read_to(in, foo);
		return *foo;
	}
}

#endif