#include "source.h"
#include <iostream>
#include <cstdint>
#include <regex>
#include <string>

using namespace std;

int main() {
    string input;
    cout<< "Input the mathematical expression:"<<endl;
    getline(cin, input); 
    regex expr_regex("\\d+|\\+|\\-|\\*|\\/|\\(|\\)");

    sregex_iterator it(input.begin(), input.end(), expr_regex);
    sregex_iterator end;

    int i=0;

    int length = 0;
    while (input[length]){
        length++;
    }
    
    const int SIZE = length; 
    string array[SIZE];
    while (it != end) {
        array[i]=it->str();
        ++it;
        i++;
    }
    
    for(int j= 0; j<SIZE; j++){
        cout<< array[j]<< endl; 
    }

    int x;
    int y;

    x = stoi(array[0]);
    y = stoi(array[2]);

    cout<< x + y << endl; 

    return 0;
}
