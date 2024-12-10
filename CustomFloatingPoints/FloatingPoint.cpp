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
			count = powerOfTwo+1;
			double newdecimalValue = value- static_cast<double>(static_cast<int>(value));
			int currentPow = -1;
			do {
				if (newdecimalValue >= std::pow(2.0, currentPow)) {
					mantissa[count] = 1;
					newdecimalValue -= std::pow(2.0, currentPow);
				}
				else {
					mantissa[count] = 0;
				}
				count++;
				currentPow -= 1;
			} while (count < 21);

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
