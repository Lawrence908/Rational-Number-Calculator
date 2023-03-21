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

#include <cstdint>
#include "reduce.cpp"


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

    /** @brief Returns whether a ratio's denominator is zero. */
    bool dividesByZero () {
        return !bottom;
    }

    /** @brief Reduces a ratio.
     * 
     * Converts a ratio to its reduced ratio. Makes the denominator positive. Uses Euclid's algorithm to find the GCD, or greatest common divisor of top and bottom. In place, divides top and bottom by the GCD.
     */
    void reduce() {
        if (bottom < 0) {
            top = -top;
            bottom = -bottom;
        }
        int64_t greatestDivisor = gcd(top, bottom);
        top = top / greatestDivisor;
        bottom = bottom / greatestDivisor;
    }

    /** @brief Gives RationalExpression access to Ratio. Only a RationalExpression can get and set in a Ratio. */
    friend class RationalExpression;
};


/**
 * @brief Finds the greatest common divisor of two integers by Euclid's algorithm.
 * @param a, b Integers.
 * @return The greatest common divisor of a, b.
 */
int64_t gcd(int64_t a, int64_t b);

#endif