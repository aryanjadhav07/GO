#include <iostream>
using namespace std;

const int SIZE = 10;
int hashTable[SIZE];

void insert(int key){
    int index = key % SIZE;
    int i = 0; 

    while(i < SIZE){
        
        int newIndex = (index + i * i) % SIZE;

        if(hashTable[newIndex] == -1) {
            hashTable[newIndex] = key;
            return;
        }
        i++;
    }
    cout << "Hash Table is full " << endl;
}

void display(){
    for(int i = 0; i < SIZE; i++){
        if(hashTable[i] != -1){

            cout << i << " --> " << hashTable[i] << endl;

        }
        else{

            cout << i << " --> " << "empty" << endl;

        }

        }
}

int main(){
    for(int i = 0; i < SIZE; i++){
        hashTable[i] = -1;
    }

    insert(27);
    insert(37);
    insert(18);
    insert(38);

       display();

    return 0;
}