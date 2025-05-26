#include <iostream>
#include <list>
using namespace std;

const int TABLE_SIZE = 10;  // Size of hash table

class HashTable {
private:
    list<pair<int, string>> table[TABLE_SIZE];

    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

public:
    void insert(int key, string value) {
        int index = hashFunction(key);
        for (auto &entry : table[index]) {
            if (entry.first == key) {
                entry.second = value;
                cout << "Key exists. Value updated.\n";
                return;
            }
        }
        table[index].push_back({key, value});
        cout << "Inserted (" << key << ", " << value << ")\n";
    }

    void find(int key) {
        int index = hashFunction(key);
        for (auto &entry : table[index]) {
            if (entry.first == key) {
                cout << "Found: " << entry.second << endl;
                return;
            }
        }
        cout << "Key not found.\n";
    }

    void remove(int key) {
        int index = hashFunction(key);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->first == key) {
                table[index].erase(it);
                cout << "Key deleted.\n";
                return;
            }
        }
        cout << "Key not found.\n";
    }

    void display() {
        cout << "\nHash Table:\n";
        for (int i = 0; i < TABLE_SIZE; ++i) {
            cout << i << ": ";
            for (auto &entry : table[i]) {
                cout << "[" << entry.first << ": " << entry.second << "] " << "-> ";
            }
            cout << "NULL" << endl;
        }
    }
};

int main() {
    HashTable dict;
    int choice, key;
    string value;

    while (true) {
        cout << "\n1. Insert\n2. Find\n3. Delete\n4. Display\n5. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key (int): ";
                cin >> key;
                cout << "Enter value (string): ";
                cin >> value;
                dict.insert(key, value);
                break;

            case 2:
                cout << "Enter key to find: ";
                cin >> key;
                dict.find(key);
                break;

            case 3:
                cout << "Enter key to delete: ";
                cin >> key;
                dict.remove(key);
                break;

            case 4:
                dict.display();
                break;

            case 5:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice.\n";
        }
    }
}
