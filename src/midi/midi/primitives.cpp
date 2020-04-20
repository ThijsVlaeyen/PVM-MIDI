#include "primitives.h"

midi::Duration midi::Duration::operator +(const midi::Duration& d) const {
	return midi::Duration(value(*this) + value(d));
}

midi::Time midi::Time::operator +(const midi::Duration& d) const {
	return midi::Time(value(*this) + value(d));
}

midi::Time midi::Duration::operator +(const midi::Time& t) const {
	return midi::Time(value(*this) + value(t));
}

midi::Duration midi::Time::operator -(const midi::Time& t) const {
	return midi::Duration(value(*this) - value(t));
}

midi::Duration midi::Duration::operator -(const midi::Duration& d) const {
	return midi::Duration(value(*this) - value(d));
}

midi::Time& midi::Time::operator +=(const midi::Duration& d)
{
	return *this = *this + d;
}

midi::Duration& midi::Duration::operator +=(const midi::Duration& r)
{
	return *this = *this + r;
}

midi::Duration& midi::Duration::operator -=(const midi::Duration& r)
{
	return *this = *this - r;
}