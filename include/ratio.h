/** Rational Calculator: Ratio class design and implementation.
 *
 *  @file ratio.h
 *  @brief A class that represents a ratio of integers p/q.
 * 
 * Uses the fixed 64-bit integer type int64_t.
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


// Design and implementation of the Ratio class.
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
    Ratio (int64_t p, int64_t q): top(p), bottom(q) {}

    /** @brief Destructor. */
    ~Ratio () {}


     /** @brief Addition operator + for ratios.
     * @return A sum of two ratios as a ratio.
     */
    Ratio operator + (Ratio right) {
        int64_t sumTop = (top * right.bottom) + (bottom * right.top);
        int64_t sumBottom = bottom * right.bottom;
        return Ratio(sumTop, sumBottom);
    }


     /** @brief Subtraction operator - for ratios.
     * @return A difference of two ratios as a ratio.
     */
    Ratio operator - (Ratio right) {
        int64_t sumTop = (top * right.bottom) - (bottom * right.top);
        int64_t sumBottom = bottom * right.bottom;
        return Ratio(sumTop, sumBottom);
    }


     /** @brief Multiplication operator * for ratios.
     * @return A product of two ratios as a ratio.
     */
    Ratio operator * (Ratio right) {
        int64_t sumTop = top * right.top;
        int64_t sumBottom = bottom * right.bottom;
        return Ratio(sumTop, sumBottom);
    }


     /** @brief Division operator / for ratios.
     * @return A quotient of two ratios as a ratio.
     */
    Ratio operator / (Ratio right) {
        int64_t sumTop = top * right.bottom;
        int64_t sumBottom = bottom * right.top;
        return Ratio(sumTop, sumBottom);
    }


    /** @brief Stream insertion operator << for ratios.
     * Output-streams a ratio's top as an integer if its bottom is 1.
     * Otherwise, output-streams the top and bottom in the form "p / q".
     * @return An ostream object for outputting a ratio to stream.
     */
    friend ostream & operator << (ostream & out, Ratio ratio) {
        out << ratio.top;
        if (ratio.bottom != 1)
	        out << " / " << ratio.bottom;
	    return out;
    }


    /** @brief Reduces a ratio.
     * Converts a ratio to its reduced fraction. Complains if the denominator is zero. Otherwise, first makes the denominator positive. Then finds the GCD of top and bottom. In place, divides top and bottom by the GCD.
     * Calls helper function gcd.
     */
    void reduce () {
        if (!bottom) {
            cout << "Division by zero: the denominator of " << this << " is zero." << endl;
            return;
        }
        if (bottom < 0) {
            top = -top;
            bottom = -bottom;
        }
        int64_t greatestDivisor = gcd(top, bottom);
        top = top / greatestDivisor;
        bottom = bottom / greatestDivisor;
    }
};


// Helper non-member functions.

/**
 * @brief Finds the greatest common divisor of two integers by Euclid's algorithm.
 * @param a, b Integers that are not both zero.
 * @return The greatest common divisor of a, b.
 */
int64_t gcd (int64_t a, int64_t b) {
    if (b == 0)
        return abs(a);
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
}

#endif