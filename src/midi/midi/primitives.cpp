#include "primitives.h"

midi::Duration midi::operator +(const midi::Duration& x, const midi::Duration& y)
{
	return midi::Duration(value(x) + value(y));
}

midi::Time midi::operator+(const midi::Time& x, const midi::Duration& y)
{
	return midi::Time(value(x) + value(y));
}

midi::Time midi::operator+(const midi::Duration& x, const midi::Time& y)
{
	return midi::Time(value(x) + value(y));
}

midi::Duration midi::operator -(const midi::Time& x, const midi::Time& y)
{
	return midi::Duration(value(x) - value(y));
}

midi::Duration midi::operator-(const midi::Duration& x, const midi::Duration& y)
{
	return midi::Duration(value(x) - value(y));
}

midi::Time& midi::operator+=(midi::Time& x, const midi::Duration& y)
{
	x = x + y;
	return x;
}

midi::Duration& midi::operator+=(midi::Duration& x, const midi::Duration& y)
{
	x = x + y;
	return x;
}

midi::Duration& midi::operator-=(midi::Duration& x, const midi::Duration& y)
{
	x = x - y;
	return x;
}