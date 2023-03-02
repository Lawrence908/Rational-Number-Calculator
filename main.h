
//
//  main.hpp
//  
//
//  Created by Rafe Saltman on 2023-02-22.
//

#ifndef main_hpp
#define main_hpp

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
  char * operation = 0;
  RationalExpression * leftOperand = 0;
  RationalExpression * rightOperand = 0;
};

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

#endif /* main_hpp */
