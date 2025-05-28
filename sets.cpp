#include <iostream>
#include <string>

using namespace std;

const int MAX = 100;

class EventParticipants {
    string coding[MAX], project[MAX], paper[MAX], mastermind[MAX];
    int cSize, pSize, ppSize, mSize;

public:
    void readData() {
        cout << "Enter number of participants in Coding: ";
        cin >> cSize;
        cout << "Enter names:\n";
        for (int i = 0; i < cSize; i++) cin >> coding[i];

        cout << "Enter number of participants in Project: ";
        cin >> pSize;
        cout << "Enter names:\n";
        for (int i = 0; i < pSize; i++) cin >> project[i];

        cout << "Enter number of participants in Paper Presentation: ";
        cin >> ppSize;
        cout << "Enter names:\n";
        for (int i = 0; i < ppSize; i++) cin >> paper[i];

        cout << "Enter number of participants in MasterMind: ";
        cin >> mSize;
        cout << "Enter names:\n";
        for (int i = 0; i < mSize; i++) cin >> mastermind[i];
    }

    bool exists(string arr[], int size, string name) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == name)
                return true;
        }
        return false;
    }

    void codingAndProject() {
        cout << "Participants in both Coding and Project:\n";
        for (int i = 0; i < cSize; i++) {
            if (exists(project, pSize, coding[i])) {
                cout << "- " << coding[i] << "\n";
            }
        }
    }

    void codingOrProjectOrMastermind() {
        string result[MAX * 3];
        int resSize = 0;

        for (int i = 0; i < cSize; i++) {
            if (!exists(result, resSize, coding[i]))
                result[resSize++] = coding[i];
        }
        for (int i = 0; i < pSize; i++) {
            if (!exists(result, resSize, project[i]))
                result[resSize++] = project[i];
        }
        for (int i = 0; i < mSize; i++) {
            if (!exists(result, resSize, mastermind[i]))
                result[resSize++] = mastermind[i];
        }

        cout << "Participants in Coding or Project or Mastermind:\n";
        for (int i = 0; i < resSize; i++) {
            cout << "- " << result[i] << "\n";
        }
    }

    void codingNotMastermind() {
        cout << "Participants in Coding but not in Mastermind:\n";
        for (int i = 0; i < cSize; i++) {
            if (!exists(mastermind, mSize, coding[i])) {
                cout << "- " << coding[i] << "\n";
            }
        }
    }

    void allEvents() {
        cout << "Participants in all events:\n";
        for (int i = 0; i < cSize; i++) {
            string name = coding[i];
            if (exists(project, pSize, name) &&
                exists(paper, ppSize, name) &&
                exists(mastermind, mSize, name)) {
                cout << "- " << name << "\n";
            }
        }
    }
};

int main() {
    EventParticipants ep;
    ep.readData();

    int choice;
    while (true) {
        cout << "\n===== MENU =====\n";
        cout << "1. Participants in Coding AND Project\n";
        cout << "2. Participants in Coding OR Project OR MasterMind\n";
        cout << "3. Participants in Coding BUT NOT in MasterMind\n";
        cout << "4. Participants in ALL Events\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: ep.codingAndProject(); break;
            case 2: ep.codingOrProjectOrMastermind(); break;
            case 3: ep.codingNotMastermind(); break;
            case 4: ep.allEvents(); break;
            case 5: cout << "Exiting...\n"; return 0;
            default: cout << "Invalid choice. Try again.\n"; break;
        }
    }

    return 0;
}
