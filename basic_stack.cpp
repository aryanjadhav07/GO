#include <iostream>
#include <stack>
using namespace std;

int main() {
    int choice, value;
    stack<int> s;

    while (true) {
        cout << "\n.... Stack Operations ...." << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Top" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                cout << value << " pushed to stack" << endl;
                break;

            case 2:
                if (!s.empty()) {
                    cout << s.top() << " popped from stack" << endl;
                    s.pop();
                } else {
                    cout << "Stack is empty" << endl;
                }
                break;

            case 3:
                if (!s.empty()) {
                    cout << "Top element is: " << s.top() << endl;
                } else {
                    cout << "Stack is empty" << endl;
                }
                break;

            case 4: {
                stack<int> temp = s;
                cout << "Stack elements from top to bottom are: ";
                if (temp.empty()) {
                    cout << "Stack is empty" << endl;
                } else {
                    while (!temp.empty()) {
                        cout << temp.top() << " ";
                        temp.pop();
                    }
                    cout << endl;
                }
                break;
            }

            case 5:
                cout << "Exiting..." << endl;
                return 0;

            default:
                cout << "Invalid choice" << endl;
                break;
        }
    }

    return 0;
}
