/** Rational Calculator: Rational expression class.
 *
 *  @file rationalexpression.h
 *  @brief A class that represents a rational expression.
 *
 *  
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
#include "rationalexpression.cpp"
using namespace std;

class RationalExpression {
private:
  Ratio * knownRatio;
  string operation;
  RationalExpression * leftOperand;
  RationalExpression * rightOperand;
public:
  RationalExpression();
  ~RationalExpression() {}
  RationalExpression(RationalExpression&&);

  Ratio getRatio();
  string getOperation();
  RationalExpression * getLeftOperand();
  RationalExpression * getRightOperand();

  void setRatio();
  void setOperation();
  void setLeftOperand();
  void setRightOperand();


  // Takes a string, interprets it as a rational expression, and returns that expression.
  RationalExpression interpret (string * token, int first, int last);

  // Takes an expression without a known ratio and returns one without operands.
  RationalExpression evaluate (RationalExpression rex);

  // Prints the enclosing expression
  RationalExpression print (string enclosing, int insertionPoint);


  // Prints a Rational expression out to the console
  void showRex (RationalExpression * rex)	{
    cout << "Rex Known Ratio: " << endl;
    rex->knownRatio->print();
    cout << "Rex Left Operand: " << rex->leftOperand << endl;
    cout << "Rex Operation: " << rex->operation << endl;
    cout << "Rex Right Operand: " << rex->rightOperand << endl;
    return;
  }

};

#endif