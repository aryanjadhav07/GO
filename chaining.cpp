#include <iostream>
#include <list>
using namespace std;

const int SIZE = 10;

class hashTable{
    
    list<int> table[SIZE];

    public : 
        int hashFunction(int key){
            return key % SIZE;
        }

        void insert(int key){
            int index = hashFunction(key);
            table[index].push_back(key);
        }

        void remove(int key){
            int index = hashFunction(key);
            table[index].remove(key);
        }

        bool search(int key){
            int index = hashFunction(key);
            for(int val : table[index]){
                if(val == key){
                    return true;
                }
            }
            return false;
        }

        void display() {
            for (int i = 0; i < SIZE; i++) {
                cout << i << " --> ";
                for (int val : table[i]) {
                    cout << val << " -> ";
                }
                cout << "empty" << endl;
            }
        }

};

int main() {
    hashTable ht;

    ht.insert(27);
    ht.insert(37);
    ht.insert(18);
    ht.insert(38);

    ht.display();

   
    cout << "Is 37 in the table? " << (ht.search(37) ? "Yes" : "No") << endl;

    
    ht.remove(37);
    cout << "After deleting 37:" << endl;
    ht.display();

    return 0;
}