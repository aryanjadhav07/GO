#include <iostream>

using namespace std;

class Set {
private:
int s[100];
int n;
public:
void readSet();
void displaySet();
Set intersection(Set b);
Set unionSet(Set b);
Set diffSet(Set b);
};

void Set::readSet() {
cout << "Enter the length of set : ";
cin >> n;

cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
}

void Set::displaySet() {
cout << "{";
    for (int i = 0; i < n; i++) {
        cout << s[i];
        if (i < n - 1) {
            cout << ", ";
        }
    }
cout << "}";
}

Set Set::intersection(Set b) {
Set t;
int k = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < b.n; j++) {
            if (s[i] == b.s[j]) {
                t.s[k] = s[i];
                k++;
                break;
            }
        }
    }
t.n = k;
return t;
}
Set Set::unionSet(Set b) {
Set t;
int k = 0;
    for (int i = 0; i < n; i++) {
        t.s[k] = s[i];
        k++;
    }
    for (int i = 0; i < b.n; i++) {
        bool flag = false;
        for (int j = 0; j < n; j++) {
            if (b.s[i] == s[j]) {
                flag = true;
                break;
            }
        }
        if (!flag) {
            t.s[k] = b.s[i];
            k++;
        }
    }
t.n = k;
return t;
}

Set Set::diffSet(Set b) {
Set t;
int k = 0;
    
    for (int i = 0; i < b.n; i++) {
        bool flag = false;
        for (int j = 0; j < n; j++) {
            if (b.s[i] == s[j]) {
                flag = true;
                break;
            }
        }
        if (!flag) {
            t.s[k] = b.s[i];
            k++;
        }
    }
t.n = k;
return t;
}

int main() {
    Set a, b, c ,d, e; 
    cout << "Enter the set A:"<<endl;
    a.readSet();
    cout << "Enter the set B:"<<endl;
    b.readSet();
    cout << "set A: ";
    a.displaySet();
    cout << endl; 
    cout << "set B: ";
    b.displaySet();
    cout << endl; 
    c = a.intersection(b);
    cout << "Intersection of A and B: ";
    c.displaySet();
    cout << endl;
     d = a.unionSet(b);
    cout << "Union of A and B: ";
    d.displaySet();
    cout << endl;
    e= a.diffSet(b);
    cout << "Difference of A and B: ";
    e.displaySet();
    cout << endl;

    return 0;
}
