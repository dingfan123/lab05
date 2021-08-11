// usestack.cpp - for CS 24 lab practice using stacks
// DINGFAN ZHENG 8652372，SHIRLEY XIE 4595534, 08/07/2021
//expression: 10 30 + 40 50 * -
// (10+30)-(40*50)=-1960
#include <iostream>
#include <cstdlib>   // for atof function
#include <stack>     // STL stack class
#include <string>    // for throwing string exceptions
#define MAXLEN 100
using namespace std;

enum TokenType {LEFT, RIGHT, ADD, SUBTRACT, MULTIPLY,
    DIVIDE, NUMBER, OTHER};

TokenType identify(char *t) {
    if (strcmp(t, "(") == 0)
        return LEFT;
    if (strcmp(t, ")") == 0)
        return RIGHT;
    if (strcmp(t, "+") == 0)
        return ADD;
    if (strcmp(t, "-") == 0)
        return SUBTRACT;
    if (strcmp(t, "*") == 0)
        return MULTIPLY;
    if (strcmp(t, "/") == 0)
        return DIVIDE;
    float value;
    if (sscanf(t, "%g", &value) == 1)
        return NUMBER;
    return OTHER;
}

double postfix (char *expression[], int numTokens){
    stack<double> numbers;

    for (int i=0; i<numTokens; i++) {
        TokenType type = identify(expression[i]);
        double leftValue, rightValue;
        switch(type) {
            case NUMBER:
                numbers.push( atof(expression[i]) );
                break;
            case ADD: case SUBTRACT: case MULTIPLY: case DIVIDE:
                if (i==0)
                    break;
                rightValue = numbers.top();
                numbers.pop();
                leftValue=numbers.top();
                numbers.pop();

                if (type == ADD)
                    numbers.push(leftValue + rightValue);
                else if (type == SUBTRACT)
                    numbers.push(leftValue - rightValue);
                else if (type == MULTIPLY)
                    numbers.push(leftValue * rightValue);
                else // type == DIVIDE
                    numbers.push(leftValue / rightValue);

                break;

            default:
                throw string("unknown token: ")
                      + string(expression[i]);
        }
    }


    if (numbers.empty())
        throw string("empty stack where one result should be");

    int result = numbers.top();
    numbers.pop();
    if (!numbers.empty())
        throw string("ERROR");

    return result;
}

int main() {
    char input[MAXLEN], *tokens[MAXLEN/2];
    cin.getline(input, MAXLEN);

    int count = 0;
    char *ptr = strtok(input, " ");
    while (ptr != 0) {
        tokens[count] = ptr;
        ++count;
        ptr = strtok(0, " ");
    }

    try {
        double result = postfix(tokens, count);
        cout << result << endl;
    }
    catch(string error) {
        cerr << error << endl;
        return 1;
    }

}
