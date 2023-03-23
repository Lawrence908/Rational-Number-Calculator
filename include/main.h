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
#include "rationalexpression.h"
using namespace std;

// Function declarations

// Generates a rational expression based on user input.
RationalExpression generateExpression();

// Breaks a string into an array of tokens that are parts of an arithmetic expression.
void tokenize (string input, string token[], int &tokenLength);


#endif /* main_h */

