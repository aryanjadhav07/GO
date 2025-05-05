#include<iostream>
using namespace std;

const int SIZE = 10;
const int PRIME = 8;
int hashTable[SIZE];

int hash1(int key){
    return key % SIZE;
}

int hash2(int key){
    return PRIME - (key % PRIME);
}

void insert(int key){

    int index1 = hash1(key);
    int index2 = hash2(key);
    int i = 0;
    while(i < SIZE){

        int newIndex = (index1 + i * index2) % SIZE;
        if(hashTable[newIndex] == -1){
            hashTable[newIndex] = key;
            return;
        }
        i++;

    }
    cout << "Hash table is full " << endl;
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