#include <iostream>
#include <string>
using namespace std;

class StringOperations {
private:
    string str;

public:
    void readString() {
        cout << "Enter the string: ";
        getline(cin, str);
    }

    void frequencyOfChar(char ch) {
        int count = 0;
        for (char c : str) {
            if (c == ch) count++;
        }
        cout << "Frequency of '" << ch << "' is: " << count << endl;
    }

    void extractSubstring(int start, int length) {
        if (start < 0 || start >= str.length() || length < 0 || (start + length) > str.length()) {
            cout << "Invalid range!" << endl;
            return;
        }
        string sub = str.substr(start, length);
        cout << "Extracted substring: " << sub << endl;
    }

    void removeCharacter(char ch) {
        string result = "";
        for (char c : str) {
            if (c != ch) result += c;
        }
        str = result;
        cout << "String after removal: " << str << endl;
    }

    void replaceSubstring(string w, string x) {
        size_t pos = str.find(w);
        if (pos == string::npos) {
            cout << "Substring not found!" << endl;
            return;
        }

        while (pos != string::npos) {
            str.replace(pos, w.length(), x);
            pos = str.find(w, pos + x.length());
        }

        cout << "String after replacement: " << str << endl;
    }

    void checkPalindrome() {
        int left = 0;
        int right = str.length() - 1;
        bool isPalindrome = true;

        while (left < right) {
            if (str[left] != str[right]) {
                isPalindrome = false;
                break;
            }
            left++;
            right--;
        }

        if (isPalindrome)
            cout << "The string is a palindrome." << endl;
        else
            cout << "The string is not a palindrome." << endl;
    }
};

int main() {
    StringOperations s;
    int choice;
    char ch;
    int start, length;
    string w, x;

    s.readString();

    while (true) {
        cout << "\nString Operations Menu:\n";
        cout << "1. Frequency of character\n";
        cout << "2. Extract substring\n";
        cout << "3. Remove a character\n";
        cout << "4. Replace a substring\n";
        cout << "5. Check palindrome\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // To flush newline from input buffer

        switch (choice) {
            case 1:
                cout << "Enter the character to count: ";
                cin >> ch;
                s.frequencyOfChar(ch);
                break;

            case 2:
                cout << "Enter starting position and length: ";
                cin >> start >> length;
                s.extractSubstring(start, length);
                break;

            case 3:
                cout << "Enter character to remove: ";
                cin >> ch;
                s.removeCharacter(ch);
                break;

            case 4:
                cout << "Enter substring to be replaced (w): ";
                cin >> w;
                cout << "Enter new substring (x): ";
                cin >> x;
                s.replaceSubstring(w, x);
                break;

            case 5:
                s.checkPalindrome();
                break;

            case 6:
                return 0;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}
