#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

void goBackN(int totalFrames, int windowSize) {
    cout << "\n--- Go-Back-N Protocol Simulation ---\n";
    int base = 0;
    while (base < totalFrames) {
        cout << "\nWindow: ";
        for (int i = base; i < min(base + windowSize, totalFrames); i++) {
            cout << "[Frame " << i << "] ";
        }

        int ackFrame;
        cout << "\nEnter the frame number that got lost or -1 for all success: ";
        cin >> ackFrame;

        if (ackFrame == -1) {
            base += windowSize;
            cout << "All frames in window acknowledged.\n";
        } else {
            cout << "Frame " << ackFrame << " lost. Resending from Frame " << ackFrame << "...\n";
            base = ackFrame;
        }
    }
}

void selectiveRepeat(int totalFrames, int windowSize) {
    cout << "\n--- Selective Repeat Protocol Simulation ---\n";
    vector<bool> ack(totalFrames, false);

    while (true) {
        cout << "\nWindow: ";
        int count = 0;
        for (int i = 0; i < totalFrames && count < windowSize; i++) {
            if (!ack[i]) {
                cout << "[Frame " << i << "] ";
                count++;
            }
        }

        int frame;
        cout << "\nEnter the frame number to simulate as lost or -1 if all received: ";
        cin >> frame;

        if (frame == -1) {
            for (int i = 0; i < totalFrames; i++) {
                if (!ack[i]) {
                    ack[i] = true;
                    cout << "Frame " << i << " acknowledged.\n";
                }
            }
        } else {
            cout << "Frame " << frame << " lost. Resending only Frame " << frame << "...\n";
        }

        // Check if all frames are acknowledged
        bool done = true;
        for (bool a : ack) {
            if (!a) {
                done = false;
                break;
            }
        }
        if (done) {
            cout << "All frames successfully received.\n";
            break;
        }
    }
}

int main() {
    int totalFrames, windowSize, choice;

    cout << "Enter total number of frames to send: ";
    cin >> totalFrames;
    cout << "Enter window size: ";
    cin >> windowSize;

    cout << "\nChoose protocol:\n1. Go-Back-N\n2. Selective Repeat\nEnter choice: ";
    cin >> choice;

    if (choice == 1) {
        goBackN(totalFrames, windowSize);
    } else if (choice == 2) {
        selectiveRepeat(totalFrames, windowSize);
    } else {
        cout << "Invalid choice.\n";
    }

    return 0;
}
