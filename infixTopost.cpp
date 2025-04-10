#include <iostream>
#include <stack>
using namespace std;

int prec(char c){
    if(c == '^') return 3;
    else if (c == '*' || c == '/') return 2;
    else if (c == '+' || c == '-') return 1;
    else return -1;
}

string infixTopostfix(string s){
    stack<char> st;
    string res;

    // Loop through each character of string s
    for(int i = 0; i < s.length(); i++){

        // Checks if the character is an operand (a-z or A_Z) and adds it to the result if yes 
        if(s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z'){
             res += s[i];
        }

        // Checks if s[i] is an opening bracket and pushes it to the stack if yes
        else if(s[i] == '('){
            st.push(s[i]);
        }

        // Checks if s[i] is a closing bracket and pops from the stack until we get '(' )
        else if(s[i] == ')'){
            while(!st.empty() && st.top() != '('){
                res += st.top();
                st.pop();
            }

            //Pops that opeing bracket from the stack 
            if(!st.empty()){
                st.pop();
            }
        }

        // Checks if s[i] is an operator and pops from the stack until we get an operator with higer precendance
        else{
            while(!st.empty() && prec(st.top()) >= prec(s[i])){
                res += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    //pops all remaining operators from the stack and adds them to the result 
    while(!st.empty()){
        res += st.top();
        st.pop();
    }

    return res;

}

int main(){
    string s;
    cout << "Enter your string : ";
    getline(cin, s);

    cout << "Your infix to postfix result is : " << infixTopostfix(s) << endl;

    return 0;
}