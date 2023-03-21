/** Rational Calculator
 *
 *  @file main.h
 *  @brief A calculator for rational number arithmetic.
 *
 *  
 *
 *  @author Rafe Saltman, Chris Lawrence, and Santiago Daza
 *  @version 0.1.0
 *  @date Feb 22, 2023
 */

#ifndef main_h
#define main_h

#include <stdio.h>
#include <string>
using namespace std;


// Data structures
struct Ratio {
	int64_t top;     // The numerator.
	int64_t bottom;  // The denominator.
};

struct RationalExpression {
	Ratio * knownRatio = 0;
	string operation;
	RationalExpression * leftOperand = 0;
	RationalExpression * rightOperand = 0;
};

// class RationalExpression {
// private:
//   Ratio * knownRatio;
//   string operation;
//   RationalExpression * leftOperand;
//   RationalExpression * rightOperand;
// public:
//   RationalExpression();
//   RationalExpression();
// }

// Function declarations

// Generates a rational expression based on user input.
RationalExpression generateExpression ();

// Breaks a string into an array of tokens that are parts of an arithmetic expression.
void tokenize (string input, int length, string token[]);

// Takes a string, interprets it as a rational expression, and returns that expression.
RationalExpression interpret (string * token, int first, int last);

// Takes an expression without a known ratio and returns one without operands.
RationalExpression evaluate (RationalExpression rex);

// Takes a fraction and returns its reduced fraction.
Ratio reduce (Ratio fraction);

// Prints a Rational expression out to the console
void showRex(RationalExpression* rex);

// Prints a ratio out to the console
void showRatio(Ratio* ratio);

#endif /* main_h */

