#pragma once
#include "freeglut.h"

struct Color
{
	unsigned char r{}, g{}, b{};

};

inline bool operator == (Color const c1, Color const c2)
{
	if ((c1.r == c2.r) && (c1.g == c2.g) && (c1.b == c2.b)) return true;
	return false;
}


