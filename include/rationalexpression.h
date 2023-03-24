/** Rational Calculator: Rational expression class design.
 *
 *  @file rationalexpression.h
 *  @brief A class that represents a rational expression.
 *
 *  @author Rafe Saltman, Chris Lawrence, and Santiago Daza
 *  @version 0.1.0
 *  @date March 21, 2023
 */

#ifndef rationalexpression_h
#define rationalexpression_h

#include <stdio.h>
#include <string>
#include "ratio.h"
using namespace std;

class RationalExpression {
private:
  Ratio * _knownRatio;
  char _operator;
  RationalExpression * _leftOperand;
  RationalExpression * _rightOperand;
public:
  RationalExpression();
  ~RationalExpression() {}
  RationalExpression(RationalExpression&&);
  RationalExpression& operator = (RationalExpression&&);

  // 
  Ratio * getRatio();

  // Takes a string, interprets it as a rational expression, and returns that expression.
  void interpret (string * token, int first, int last);

  // Takes an expression without a known ratio and returns one without operands.
  void evaluate ();

  // Prints a Rational expression out to the console
  void print ();

  // Prints the enclosing expression.
  void printEnclosing (string enclosing, int insertionPoint);
};

#endif