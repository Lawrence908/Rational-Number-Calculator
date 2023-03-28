/** Rational Calculator: Rational expression class header.
 *
 *  @file rationalexpression.h
 *  @brief A class that represents a rational expression.
 *
 *  In this class header file, comments will shorten RationalExpression to Rex.
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
  // Rex constructors, destructor, and move assignment.
  RationalExpression ();
  RationalExpression (Ratio *);
  ~RationalExpression () {}
  RationalExpression (RationalExpression &&);
  RationalExpression & operator = (RationalExpression &&);

  // Ratio getter.
  Ratio * getRatio();

  // Gives whether a Rex has both operands.
  bool hasOperands();

  // Converts a sequence of tokens into a Rex.
  void interpret (string * token, int first, int last);

  // Evaluates a Rex.
  void evaluate ();

  // Prints a Rational expression out to the console
  void print ();

  // Prints the enclosing expression.
  void printEnclosing (string enclosing, int insertionPoint);
};

#endif