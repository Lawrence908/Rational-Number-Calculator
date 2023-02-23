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

#include "main.h"
#include <iostream>
#include <cstdint>
#include <regex>
#include <string>
using namespace std;



int main () {
  RationalExpression rex = generateExpression();
  
  rex = evaluate(rex);
  
  Ratio * result;
  if (rex.knownRatio) {
    result = rex.knownRatio;
    cout << result->top << " / " << result->bottom << endl;
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
  while (input[length]) {
    length++;
  }
  
  string token[length];
  tokenize(input, length, token);
  
  
  rex = interpret(token);
  return rex;
}


// Breaks a string into an array of tokens that are parts of an arithmetic expression.
void tokenize (string input, int length, string token[]) {
  regex expr_regex("\\d+|\\+|\\-|\\*|\\/|\\(|\\)");
  
  sregex_iterator it(input.begin(), input.end(), expr_regex);
  sregex_iterator end;
  
  int i=0;
  
  while (it != end) {
    token[i] = it->str();
    cout << token[i] << " ";
    it++;
    i++;
  }
  cout << endl;
}


// Takes a string with arithmetic in S-expression form, interprets it as a rational expression, and returns that expression.
RationalExpression interpret (string input) {
  RationalExpression rex;
  
  for (int i = first; i <= last; i++) {
  }
  
  return rex;
}


// Takes an expression without a known ratio and returns one without operands.
RationalExpression evaluate (RationalExpression rex) {
  return rex;
}


// Takes a fraction and returns its reduced fraction.
Ratio reduce (Ratio fraction) {
  return fraction;
}
