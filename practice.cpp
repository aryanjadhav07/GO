#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int precedance(char op){
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    if(op == '^') return 3;
    return 0;
}

bool isOperator(char c){
    return(!isalnum(c) && c != '(' && c != ')');
}

string infixtopostfix(string infix){
        
}