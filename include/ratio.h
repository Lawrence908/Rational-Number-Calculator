/** Rational Calculator: Ratio class.
 *
 *  @file ratio.h
 *  @brief A class that represents a ratio.
 *
 *  
 *
 *  @author Rafe Saltman, Chris Lawrence, and Santiago Daza
 *  @version 0.1.0
 *  @date March 21, 2023
 */

#ifndef ratio_h
#define ratio_h

// Included libraries and helper function declarations.
#include <cstdint>
#include <iostream>
using namespace std;
int64_t gcd(int64_t a, int64_t b);


class Ratio {
private:
	int64_t top;     // The numerator.
	int64_t bottom;  // The denominator.
public:
    /** @brief Default constructor. Returns the ratio 0/1. */
    Ratio (): top(0), bottom(1) {}

    /** @brief Integer constructor. Given n, returns the ratio n/1. */
    Ratio (int64_t integer): top(integer), bottom(1) {}

    /** @brief Fraction constructor. Given p and q, returns the ratio p/q. */
    Ratio (int64_t p, int64_t q): top(p), bottom(q) {};

    /** @brief Destructor. */
    ~Ratio () {}


     /** @brief Overloaded + addition.
     * 
     * Given two ratios, returns their sum as a ratio.
     */
    Ratio operator + (Ratio right) {
        int64_t sumTop = top * right.bottom + bottom * right.top;
        int64_t sumBottom = bottom * right.bottom;
        return Ratio(sumTop, sumBottom);
    }


     /** @brief Overloaded - subtraction.
     * 
     * Given two ratios, returns their sum as a ratio.
     */
    Ratio operator - (Ratio right) {
        int64_t sumTop = top * right.bottom - bottom * right.top;
        int64_t sumBottom = bottom * right.bottom;
        return Ratio(sumTop, sumBottom);
    }


     /** @brief Overloaded * multiplication.
     * 
     * Given two ratios, returns their sum as a ratio.
     */
    Ratio operator * (Ratio right) {
        int64_t sumTop = top * right.top;
        int64_t sumBottom = bottom * right.bottom;
        return Ratio(sumTop, sumBottom);
    }


     /** @brief Overloaded / division.
     * 
     * Given two ratios, returns their sum as a ratio.
     */
    Ratio operator / (Ratio right) {
        int64_t sumTop = top * right.bottom;
        int64_t sumBottom = bottom * right.top;
        return Ratio(sumTop, sumBottom);
    }


    /** @brief Reduces a ratio.
     * 
     * Converts a ratio to its reduced ratio. Makes the denominator positive. Finds the GCD of top and bottom. In place, divides top and bottom by the GCD.
     */
    void reduce () {
        if (bottom < 0) {
            top = -top;
            bottom = -bottom;
        }
        int64_t greatestDivisor = gcd(top, bottom);
        if (!greatestDivisor) {
            cout << "Division by zero: numerator " << top << " and denominator " << bottom
                 << " have no greatest common divisor." << endl;
            return;
        }
        top = top / greatestDivisor;
        bottom = bottom / greatestDivisor;
    }

    void print () {
        cout << top << " / " << bottom << endl;
    }

    /** @brief Gives RationalExpression access to Ratio. Only a RationalExpression can get and set in a Ratio. */
    friend class RationalExpression;
};


/**
 * @brief Finds the greatest common divisor of two integers by Euclid's algorithm.
 * @param a, b Integers.
 * @return The greatest common divisor of a, b.
 */
int64_t gcd(int64_t a, int64_t b) {
    int64_t q;
    int64_t r = 1;
    while (r != 0) {
        q = a / b;
        r = a - (q * b);
        if (r == 0)
            return abs(b);
        a = b;
        b = r;
    }
    return 0;
}

#endif