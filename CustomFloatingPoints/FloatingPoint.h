#pragma once
#include <math.h>       /* log2 */
#include <cmath>

#ifndef FloatingPoint_H
#define FloatingPoint_H


class FloatingPoint {

public:
	bool expo[8] = { 0 };
	bool mantissa[21] = { 0 };
	bool sign = 0;
	int bias = 127;
	FloatingPoint(double value);
};

#endif