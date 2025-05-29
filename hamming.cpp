#include<iostream>
using namespace std;

const int n = 7;

int main(){

int arr[n];
cout << "Enter the received data (p1, p2, d3, p4, d5, d6, d7) : ";
for(int i = 0 ; i < n; i++){
    cin >> arr[i];
}

int p1 = arr[0] ^ arr[2] ^ arr[4] ^ arr[6];
int p2 = arr[1] ^ arr[2] ^ arr[5] ^ arr[6];
int p4 = arr[3] ^ arr[4] ^ arr[5] ^ arr[6];

int error = p4 * 4 + p2 * 2 + p1 * 1;

if(error == 0){
    cout << "No error detected. " << endl;
}
else{
    cout << "Error detected at position " << error << endl;
    arr[error - 1] = (arr[error - 1] == 0 ? 1 : 0);

    cout << "Corrected data is : ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " " ;
    }
}

cout << endl;
cout << "Extracted data bits are : " << arr[2] << " " << arr[4] << " " << arr[5] << " " << arr[6] << endl;

}
