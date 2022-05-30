#include "PolishNotation.h"
#include <iostream>
#include <string>
#include <stack>
#include <sstream>
using namespace std;


PolishNotation::PolishNotation(){
    prefix = " ";
}

PolishNotation::PolishNotation (string expression){
    prefix = expression;
}


string PolishNotation::convertPrefixToinfix(){
    string infix = "";

    stack<int> stk;

    int validExpression = 1;
    int value = 0;
    int digits = 0;

    int wordLength = prefix.length();
    for (int i = wordLength - 1; i >= 0 && validExpression == 1; i--){
        char ch = prefix[i];
        if (ch == ' '){
            digits = 0;
        }
        else if (isdigit(ch)){
            digits++;

            if (digits == 1){
                value = ch - '0';
            }
            else{
                value = value + (ch - '0') * 10;
                stk.pop();
            }

            stk.push(value);

            if (value > 99){
                validExpression = 0;
            }
        }

        else if ((ch == '+' || ch == '-' || ch == '*' || ch == '/') && stk.size() >= 2 && infix.length() == 0){
            int num1 = stk.top();
            stk.pop();

            int num2 = stk.top();
            stk.pop();

            ostringstream oss;

            oss << infix << "(" << num1 << " " << ch << " " << num2 << ")";
            infix = oss.str();

            digits = 0;
        }

        else if ((ch == '+' || ch == '-' || ch == '+' || ch == '/') && stk.size() == 1 && infix.length() > 0){
            int num = stk.top();
            stk.pop();

            ostringstream oss;

            oss << infix << " " << ch << " " << num;
            infix = oss.str();

            digits = 0;
        }

        else if ((ch == '+' || ch == '-' || ch == '*' || ch == '/') && stk.size() >= 2 && infix.length() > 0)
        {
            int num = stk.top();
            stk.pop();

            ostringstream oss;

            oss << "(" << infix << " " << ch << " " << num << ") ";
            infix = oss.str();

            digits = 0;
        }
        else
        {
            validExpression = 0;
        }
    }

    if (validExpression == 0 || stk.size() > 0){
        infix = "Error";
    }

    return infix;

}

int PolishNotation::computePrefixExpression(){
    int result = 0;

    stack<int> stk;

    int validExpression = 1;
    int value = 0;
    int digits = 0;

    for (int i = prefix.length() - 1; i >= 0 && validExpression == 1; i--)
    {
        char ch = prefix[i];
        if (ch == ' '){
            digits = 0;
        }
        else if (isdigit(ch))
        {
            digits++;

            if(digits == 1){
                value = ch - '0';
            }
            else if (isdigit(ch)){
                digits++;

                if(digits == 1){
                    value = ch - '0';
                }
                else{
                    value = value + (ch - '0') * 10;
                    stk.pop();
                }

                stk.push(value);

                if (value > 99){
                    validExpression = 0;
                }
            }
        }

            else if (ch == '+' && stk.size() >= 2){
                int num1 = stk.top();
                stk.pop();

                int num2 = stk.top();
                stk.pop();

                stk.push(num1 + num2);
                digits = 0;
            }

            else if (ch == '-' && stk.size() >= 2){
                int num1 = stk.top();
                stk.pop();

                int num2 = stk.top();
                stk.pop();

                stk.push(num1 - num2);
                digits = 0;
            }

            else if (ch == '*' && stk.size() >= 2){
                int num1 = stk.top();
                stk.pop();

                int num2 = stk.top();
                stk.pop();

                stk.push(num1 * num2);
                digits = 0;
            }
            else if (ch == '/' && stk.size() >= 2){
                int num1 = stk.top();
                stk.pop();

                int num2 = stk.top();
                stk.pop();

                stk.push(num1/num2);
                digits = 0;
            }

            else{
                validExpression = 0;
            }
    }

    if (validExpression == 1 && !stk.empty()){
        result = stk.top();
        stk.pop();
        }

    return result;
}