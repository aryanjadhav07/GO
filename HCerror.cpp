#include <iostream>
using namespace std;

int main(){

    const int n = 7;
    int arr[n];

    cout << "Enter the 7-bit received data (p1, p2, d3, p4, d5, d6, d7) : " << endl;

    for(int i = 1; i <= n ; i++){
        cin >> arr[i-1];
    }

    // calculate the parity bits 

    int p1 = arr[0] ^ arr[2] ^ arr[4] ^ arr[6];
    int p2 = arr[1] ^ arr[2] ^ arr[5] ^ arr[6];
    int p4 = arr[3] ^ arr[4] ^ arr[5] ^ arr[6];

    int error_position = p4 * 4 + p2 * 2 + p1 * 1;

    if(error_position == 0){
        cout << "No error detected. Data is correct." << endl;
    }
    else{
        cout << "Error detected at bit position : " << error_position << endl;
        arr[error_position -1] = (arr[error_position -1] == 0 ? 1 : 0);

        cout << "The corrected data is : " ;
    for(int i = 1; i <= n ; i++){
        cout << arr[i-1] << " ";
    }
    }

    cout << endl;

    cout << "Extracted data bits are (d3, d5, d6, d7) : " << arr[2] << " " << arr[4] << " " << arr[5] << " " << arr[6] << endl;





    


    return 0;
}