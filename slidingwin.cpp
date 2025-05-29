#include <iostream>
#include <vector>
#include <set>
using namespace std;

void gobackN(int totalFrames, int windowSize){
    cout << "\n--- Go Back N Protocol Simulation ---\n";
    int base = 0;

    while (base < totalFrames) {
        cout << "Window: ";
        for (int i = base; i < min(base + windowSize, totalFrames); i++) {
            cout << "[Frame " << i << "] ";
        }

        int ackFrame;
        cout << "\nEnter the frame that is lost or -1 to acknowledge all: ";
        cin >> ackFrame;

        if (ackFrame == -1) {
            base += windowSize;
            cout << "All frames in window are acknowledged.\n";
        } else {
            cout << "Frame " << ackFrame << " is lost. Resending from Frame " << ackFrame << "...\n";
            base = ackFrame;
        }
    }
}



void selectiveRepeat(int totalFrames, int windowSize) {
    cout << "\n--- Selective Repeat Protocol Simulation ---\n";
    int base = 0;
    vector<bool> acked(totalFrames, false);

    while (base < totalFrames) {
        cout << "Window: ";
        for (int i = base; i < min(base + windowSize, totalFrames); i++) {
            cout << "[Frame " << i << (acked[i] ? "*" : "") << "] ";
        }

        int lostFrame;
        cout << "\nEnter frame number that is lost or -1 to acknowledge all in window: ";
        cin >> lostFrame;

        if (lostFrame == -1) {
            for (int i = base; i < min(base + windowSize, totalFrames); i++) {
                acked[i] = true;
            }
            while (base < totalFrames && acked[base]) {
                base++;
            }
            cout << "All frames in window acknowledged.\n";
        } else if (lostFrame >= base && lostFrame < base + windowSize) {
            cout << "Frame " << lostFrame << " is lost. Resending only Frame " << lostFrame << "...\n";
            acked[lostFrame] = false;
            for (int i = base; i < min(base + windowSize, totalFrames); i++) {
                if (i != lostFrame) acked[i] = true;
            }
            while (base < totalFrames && acked[base]) {
                base++;
            }
        } else {
            cout << "Invalid frame number.\n";
        }
    }
}

int main() {
    int totalFrames, windowSize, choice;

    cout << "Enter the total number of frames: ";
    cin >> totalFrames;

    cout << "Enter the window size: ";
    cin >> windowSize;

    cout << "Choose the protocol to simulate:\n";
    cout << "1. Go Back N\n";
    cout << "2. Selective Repeat\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        gobackN(totalFrames, windowSize);
    } else if (choice == 2) {
        selectiveRepeat(totalFrames, windowSize);
    } else {
        cout << "Invalid choice. Exiting...\n";
    }

    return 0;
}
