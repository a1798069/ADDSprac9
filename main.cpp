#include "PolishNotation.h"
#include <iostream>
#include <sstream>

using namespace std;

int main(){
    string prefix;

    cout << "input: ";
    getline (cin, prefix);

    PolishNotation polish(prefix);

    string infix = polish.convertPrefixToinfix();

    cout << "output: " << infix;

    if (infix.compare("Error") != 0){
        int result = polish.computePrefixExpression();

        cout << " = " << result;
    }

    cout << endl << endl;

    return 0;

}