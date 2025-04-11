#include<bits/stdc++.h>
#include<vector>
#include<cmath>

using namespace std;

int main(){
    string str;
    char clss;
    int lastdigit;

    cout << "Enter the IP Address: " << endl;
    getline(cin, str);
    vector <string> temp;
    string current;

    for (char ch : str) {
        if (ch == '.') {
            if (!current.empty()) {
                temp.push_back(current);
                current.clear();
            }
        } else {
            current += ch;
        }
    }
    if (!current.empty()) {
        temp.push_back(current);
    }

}