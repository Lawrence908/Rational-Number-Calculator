#include <iostream>
#include <regex>

using namespace std;

int main() {
    string input = "1 + 2 * (3 - 4) / 5";
    regex expr_regex("\\d+|\\+|\\-|\\*|\\/|\\(|\\)");

    sregex_iterator it(input.begin(), input.end(), expr_regex);
    sregex_iterator end;

    while (it != end) {
        cout << it->str() << endl;
        ++it;
    }

    return 0;
}
