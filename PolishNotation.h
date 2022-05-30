#ifndef POLISHNOTATION_H
#define POLISHNOTATION_H
#include <string>
#include <stack>
#include <iostream>

using namespace std;

class PolishNotation {
    public:
        PolishNotation();
        PolishNotation (string expression);

        void setPrefixExpression (string expression);
        string convertPrefixToinfix ();
        int computePrefixExpression();
    
    private:
        string prefix;
};

#endif