// CustomFloatingPoints.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "FloatingPoint.h"

int convert_to_decimal(bool arr[8]) {
    int result = 0;
    int currentExpo = 0;
    for (int i = 7; i >= 0; i--) {
        if (arr[i] == true) {
            result += static_cast<int>(pow(2, currentExpo));
        }
        currentExpo += 1;
    }
    return result;
}

FloatingPoint add(FloatingPoint x, FloatingPoint y)
{
    FloatingPoint result = FloatingPoint(0);
    FloatingPoint newTemp = FloatingPoint(0);
    bool remainder = false;
    if (convert_to_decimal(x.expo) > convert_to_decimal(y.expo)) {
        // right shift y until match 
        int difference = convert_to_decimal(x.expo) - convert_to_decimal(y.expo);
        for (int i = 0; i < 8; i++) {
            newTemp.expo[i] = x.expo[i];
            result.expo[i] = x.expo[i];
        }
        for (int i = 0; i < 21; i++) {
            int newIndex = i + difference;
            if (newIndex < 21) {
                newTemp.mantissa[newIndex] = y.mantissa[i];
            }
        }

        bool remainder = false;
        for (int i = 20; i >= 0; i--) {
            if (newTemp.mantissa[i] == true && x.mantissa[i] == true) {
                remainder = true;
                result.mantissa[i] = false;
            }
            else if ((newTemp.mantissa[i] == true && remainder) || x.mantissa[i] == true && remainder) {
                remainder = true;
                result.mantissa[i] = false;
            }
            else if (newTemp.mantissa[i] == true || x.mantissa[i] == true) {
                remainder = false;
                result.mantissa[i] = true;
            }
            else if (remainder && newTemp.mantissa[i] == false || remainder && x.mantissa[i] == false) {
                remainder = false;
                result.mantissa[i] = true;
            }
            else {
                remainder = false;
                result.mantissa[i] = false;
            }
        }
    }
    else if (y.expo > x.expo) {
        // right shift x until match

        int difference = convert_to_decimal(y.expo) - convert_to_decimal(x.expo);
        for (int i = 0; i < 8; i++) {
            newTemp.expo[i] = y.expo[i];
            result.expo[i] = y.expo[i];
        }
        for (int i = 0; i < 21; i++) {
            int newIndex = i + difference;
            if (newIndex < 21) {
                newTemp.mantissa[newIndex] = x.mantissa[i];
            }
        }
        
        for (int i = 20; i >= 0; i--) {
            if (newTemp.mantissa[i] == true && y.mantissa[i] == true) {
                remainder = true;
                result.mantissa[i] = false;
            }
            else if ((newTemp.mantissa[i] == true && remainder) || y.mantissa[i] == true && remainder) {
                remainder = true;
                result.mantissa[i] = false;
            }
            else if (newTemp.mantissa[i] == true || y.mantissa[i] == true) {
                remainder = false;
                result.mantissa[i] = true;
            }
            else if (remainder && newTemp.mantissa[i] == false || remainder && y.mantissa[i] == false) {
                remainder = false;
                result.mantissa[i] = true;
            }
            else {
                remainder = false;
                result.mantissa[i] = false;
            }
        }
    }
    else {
        // start adding
        for (int i = 20; i >= 0; i--) {
            if (x.mantissa[i] == true && y.mantissa[i] == true) {
                remainder = true;
                result.mantissa[i] = false;
            }
            else if ((x.mantissa[i] == true && remainder) || y.mantissa[i] == true && remainder) {
                remainder = true;
                result.mantissa[i] = false;
            }
            else if (x.mantissa[i] == true || y.mantissa[i] == true) {
                remainder = false;
                result.mantissa[i] = true;
            }
            else if (remainder && x.mantissa[i] == false || remainder && y.mantissa[i] == false) {
                remainder = false;
                result.mantissa[i] = true;
            }
            else {
                remainder = false;
                result.mantissa[i] = false;
            }
        }
    }
    if (remainder) {
        FloatingPoint tempValue = FloatingPoint(0);
        bool expoRemainder = true;
        for (int i = 7; i >= 0; i--) {
            if (result.expo[i] == true && expoRemainder) {
                tempValue.expo[i] = false;
            }
            else if (expoRemainder && result.expo[i] == false) {
                tempValue.expo[i] = true;
                expoRemainder = false;
            }
            else {
                tempValue.expo[i] = result.expo[i];
            }
        }
        for (int i = 0; i < 21; i++) {
            if (i == 0) {
                tempValue.mantissa[i] = true;
            }
            else {
                tempValue.mantissa[i] = result.mantissa[i - 1];
            }
        }
        return tempValue;
    }
    return result;
}

int main()
{
    FloatingPoint pointX = FloatingPoint(16);
    FloatingPoint pointY = FloatingPoint(16);
    FloatingPoint result = add(pointX, pointY);
    std::cout << "Hello World!\n";
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
