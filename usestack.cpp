// usestack.cpp - for CS 24 lab practice using stacks
// DINGFAN ZHENG, 08/07/2021

#include "intstack.h"
#include <iostream>
using namespace std;

int main() {
    Stack s;

    s.push(10);
    s.push(20);

    while (!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}
