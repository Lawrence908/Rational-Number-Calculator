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


// Included library, header, and source files
#include <iostream>
#include <cstdint>
#include <regex>
#include <string>
#include "../include/ratio.h"
#include "../include/rationalexpression.h"
#include "../include/main.h"
#include "rationalexpression.cpp"
using namespace std;


int main (int argc, char ** argv) {
	RationalExpression rex;
	string input = "";
	if (argc > 1) {
		for (int i = 1; i < argc; i++) {
			input += argv[i];
		}
	} else {
		cout << "Enter an arithmetic expression:" << endl;
		getline(cin, input);
	}

	int inputLength = 0;
		while (input[inputLength])	{
		inputLength++;
	}
	
	string token[inputLength];
	int tokenLength;
	tokenize(input, token, tokenLength);

	// for (int i = 0; i < tokenLength; i++)
	// {
	// 	cout << token[i] << endl;
	// }

	if (token[0] == "(") {
		rex.interpret(token, 1, tokenLength - 2);  //strip off parentheses
	} else {
		rex.interpret(token, 0, tokenLength - 1);
	}

// cout << "top: "; rex.getRatio()->print(); cout << endl;

	// rex.print();

	rex.evaluate();

cout<< "Evaluate complete." << endl;

    // rex.print();

	Ratio * result;
	if (rex.getRatio())	{
		result = rex.getRatio();
		// result->print();
        cout << "Result = " << *result << endl;
	} else {
		
	}


	return 0;
}


// Breaks a string into an array of tokens that are parts of an arithmetic expression.
void tokenize (string input, string token[], int &tokenLength)	{
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
	tokenLength = i;
}