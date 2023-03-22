#include <iostream>
#include "rationalexpression.h"
using namespace std;

RationalExpression::RationalExpression (): knownRatio(0), operation("/"), leftOperand(0), rightOperand(0) {}
RationalExpression::RationalExpression (RationalExpression&& temp):
    knownRatio(temp.knownRatio), operation(temp.operation), leftOperand(temp.leftOperand), rightOperand(temp.rightOperand) {
    temp.knownRatio = 0;
    temp.operation = "";
    temp.leftOperand = 0;
    temp.rightOperand = 0;
}

Ratio * RationalExpression::getRatio() {
    return knownRatio;
}

string RationalExpression::getOperation() {}
RationalExpression * RationalExpression::getLeftOperand() {}
RationalExpression * RationalExpression::getRightOperand() {}

void RationalExpression::setRatio() {}
void RationalExpression::setOperation() {}
void RationalExpression::setLeftOperand() {}
void RationalExpression::setRightOperand() {}


// Takes a string with arithmetic in S-expression form, interprets it as a rational expression, and returns that expression.
void RationalExpression::interpret (string * token, int first, int last)	{
	RationalExpression rex;

	rex.knownRatio = NULL;
	int operandsCount = 0;
	for (int i = first; i <= last; i++)	{
		if (token[i] == ")")	{
			return;
		}
		if ((token[i] == "+") || (token[i] == "-") || (token[i] == "*") || (token[i] == "/"))	{
			rex.operation = token[i];
cout << token[i] << endl;
cout << rex.operation << endl;

		} else if (token[i] == "(")	{
			int operandFirst = i + 1;
			int operandLast;
			int parenthesisCount = 1;
			for (int j = i+1; j <= last; j++)	{
				if (token[j] == "(") {
					parenthesisCount++;
				} else if (token[j] == ")")	{
					parenthesisCount--;
					if (parenthesisCount == 0)	{
						operandLast = j - 1;
						break;  //out of for(j...)
					}
				}
			}
			if (operandsCount == 0)	{
				rex.leftOperand->interpret(token, operandFirst, operandLast);

			} else if (operandsCount == 1)	{
				rex.rightOperand->interpret(token, operandFirst, operandLast);
			}
cout << "operandsCount++" << endl;
			operandsCount++;
		} else {
				Ratio ratio;
				ratio.top = stoi(token[i]);
cout << stoi(token[i]) << endl;
				ratio.bottom = 1;
				RationalExpression rexKnown;
				rexKnown.knownRatio = &ratio;
				rexKnown.operation = "/";
				rexKnown.leftOperand = NULL;
				rexKnown.rightOperand = NULL;
			if (operandsCount == 0)	{
				rex.leftOperand = &rexKnown;
cout << "rex.leftOperand = " << rexKnown.knownRatio->top << endl;
			} else if (operandsCount == 1)	{
				rex.rightOperand = &rexKnown;
cout << "rex.rightOperand = " << rexKnown.knownRatio->top << endl;
			}
cout << "operandsCount++" << endl;
			operandsCount++;
cout << "Iterating i" << endl;
		}
	}
}


// Takes an expression without a known ratio and returns one without operands.
void RationalExpression::evaluate () {
}

// Prints the enclosing expression
void RationalExpression::print (string enclosing, int insertionPoint) {
}
