#include "FloatingPoint.h"


#include <math.h>       /* log2 */
#include <cmath>


FloatingPoint::FloatingPoint(double value) {
	// Convert number into binary
	if (value != 0) {
		{
			if (value < 0) {
				sign = true;
			}
			else {
				sign = false;
			}
			int powerOfTwo = std::floor(log2(value));
			int wholeNum = static_cast<int>(value);
			int count = powerOfTwo;
			while (wholeNum > 0) {
				if (wholeNum == 1) {
					mantissa[count] = 1;
					break;
				}
				mantissa[count] = wholeNum % 2;
				wholeNum = wholeNum / 2;
				count -= 1;
			}
			int newExponent = powerOfTwo + bias;
			count = 7;
			while (newExponent > 0) {
				if (newExponent == 1) {
					expo[count] = 1;
					break;
				}
				expo[count] = newExponent % 2;
				newExponent = newExponent / 2;
				count -= 1;
			}

		}
	}
}
