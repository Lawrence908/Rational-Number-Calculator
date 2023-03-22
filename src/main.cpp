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
#include "ratio.h"
#include "rationalexpression.h"
#include "main.h"

using namespace std;



int main ()	{
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
	rex.interpret(token, 1, length - 2);  //strip off parentheses
	rex.evaluate();

	Ratio * result;
	if (rex.getRatio())	{
		result = rex.getRatio();
		result->print();
	} else {
		
	}


	return 0;
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