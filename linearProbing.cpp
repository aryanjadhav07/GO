#include <iostream>
using namespace std;

const int SIZE = 10;
int hashTable[SIZE];

void insert(int key){
int index = key % SIZE;
int i = 0;

while(hashTable[(index + i) % SIZE] != -1){
    i++;
    if(i == SIZE){
        cout << "Hash table is full " << endl;
        return ;
    }
}

    hashTable[(index + i) % SIZE] = key;

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