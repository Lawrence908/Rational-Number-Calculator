/** Rational Calculator
 *
 *  @file main.cpp
 *  @brief A calculator for rational number arithmetic.
 *
 *  
 *
 *  @author Rafe Saltman, Chris Lawrence, and Santiago Daza
 *  @version 0.1.0
 *  @date Feb 22, 2023
 */


// Includes

#include <iostream>
#include <cstdint>
#include <regex>
#include <string>
#include "main.h"
#include "rationalexpression.h"
using namespace std;



int main ()	{
	RationalExpression rex;
	rex(generateExpression());

cout << "EXIT generate" << endl;

cout << "Onwards to evaluate" << endl;

	rex(evaluate(rex));

	Ratio * result;
	if (rex.knownRatio)	{
		result = rex.knownRatio;
		result->print();
	} else {
		
	}


	return 0;
}


// Generates a rational expression based on user input.
RationalExpression generateExpression () {
	RationalExpression rex;

	string input;

	cout << "Enter an arithmetic expression:" << endl;

	getline(cin, input);
	
	int length = 0;
	while (input[length])	{
		length++;
	}
	
	string token[length];
	tokenize(input, length, token);
		
	rex(RationalExpression::interpret(token, 1, length - 2));  //strip off parentheses

	return rex;
}


// Breaks a string into an array of tokens that are parts of an arithmetic expression.
void tokenize (string input, int length, string token[])	{
	regex expr_regex("\\d+|\\+|\\-|\\*|\\/|\\(|\\)");
	
	sregex_iterator it(input.begin(), input.end(), expr_regex);
	sregex_iterator end;
	
	int i=0;
	
	while (it != end)	{
		token[i] = it->str();
		cout << token[i] << " ";
		it++;
		i++;
	}
	cout << endl;
}


// Takes a string with arithmetic in S-expression form, interprets it as a rational expression, and returns that expression.
RationalExpression RationalExpression::interpret (string * token, int first, int last)	{
	RationalExpression rex;

	rex.knownRatio = NULL;
	int operandsCount = 0;
	for (int i = first; i <= last; i++)	{
		if (token[i] == ")")	{
			return rex;
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
				RationalExpression rexLeft = interpret(token, operandFirst, operandLast);
				rex.leftOperand = &rexLeft;

			} else if (operandsCount == 1)	{
				RationalExpression rexRight = interpret(token, operandFirst, operandLast);
				rex.rightOperand = &rexRight;

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
	
	return rex;
}


// Takes an expression without a known ratio and returns one without operands.
RationalExpression RationalExpression::evaluate (RationalExpression rex)	{
	return rex;
}