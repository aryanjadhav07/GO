#include <iostream>
#include <vector>

using namespace std;

void gobackN(int totalFrames, int windowSize){
    cout << "\n --- Go Back N Protocol Simulation --- \n";
    int base = 0;

    while(base < totalFrames){
        cout << "Window : ";
        for(int i = base; i < min(base + windowSize, totalFrames); i++){
            cout << "[Frame " << i << "] ";
        }

        int ackFrame;
        cout << "\n Enter the fram that is lost or -1 to acknowledge all : ";
        cin >> ackFrame;

        if(ackFrame == -1){
            base += windowSize;
            cout << "All frames in window are acknowledged.\n";
        }
        else{
            cout << "Frame " << ackFrame << " is lost. Resending from Frame " << ackFrame << "...\n";
            base = ackFrame;
        }
    }
}

int main(){

    int totalFrames, windowSize, choice;

    cout << "Enter the total number of frames : ";
    cin >> totalFrames;

    cout << "Enter the window size : ";
    cin >> windowSize;

    cout << "Choose the protocol to simulate: \n 1. Go Back N \n 2. Selective Repeat \n";
    cin >> choice;

    if(choice == 1){
        gobackN(totalFrames, windowSize);
    }
    else{
        cout << "Invalid Choice. Exiting...\n";
    }
}