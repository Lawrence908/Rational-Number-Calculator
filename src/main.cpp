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
#include <cctype>
#include "../include/ratio.h"
#include "../include/rationalexpression.h"
#include "../include/main.h"
#include "rationalexpression.cpp"
using namespace std;


int main (int argc, char ** argv) {
	cout << "Rational Calculator v0.1." << endl;
	RationalExpression rex;
	string input = "";
	if (argc > 1) {
		for (int i = 1; i < argc; i++)
			input += argv[i];
	} else {
		cout << "rc > ";
		getline(cin, input);
	}

	// Program loop. An input starting with 'q' quits the program.
	while (tolower(input[0]) != 'q') {
		int inputLength = 0;
			while (input[inputLength])	{
			inputLength++;
		}
		
		string token[inputLength];
		int tokenLength;
		tokenize(input, token, tokenLength);

		if (token[0] == "(") {
			rex.interpret(token, 1, tokenLength - 2);  //strip off parentheses
		} else {
			rex.interpret(token, 0, tokenLength - 1);
		}

		rex.evaluate();

		Ratio * result;
		if (rex.getRatio())	{
			result = rex.getRatio();
			cout << "Result = " << *result << endl;
		}

		cout << "rc > ";
		getline(cin, input);
	}
	return 0;
}


// Breaks a string into an array of tokens that are parts of an arithmetic expression.
void tokenize (string input, string token[], int & tokenLength)	{
	regex expr_regex("\\d+|\\+|\\-|\\*|\\/|\\(|\\)");
	sregex_iterator it(input.begin(), input.end(), expr_regex);
	sregex_iterator end;
	int i = 0;
	cout << "Tokenized: ";
	while (it != end) {
		token[i] = it->str();
		cout << token[i] << " ";
		it++;
		i++;
	}
	cout << endl;
	tokenLength = i;
}