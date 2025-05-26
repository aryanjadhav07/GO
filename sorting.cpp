#include <iostream>
using namespace std;

const int MAX = 100;

void inputScores(float arr[], int &n) {
    cout << "Enter number of students: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter percentage for student " << i + 1 << ": ";
        cin >> arr[i];
    }
}

void displayScores(float arr[], int n) {
    cout << "Scores: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// 1. Selection Sort
void selectionSort(float arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int minIndex = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        float temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

// 2. Bubble Sort
void bubbleSort(float arr[], int n) {
    for (int i = 0; i < n-1; i++) {

        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                float temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;

            }
        }

    }
}

// 3. Insertion Sort
void insertionSort(float arr[], int n) {
    for (int i = 1; i < n; i++) {
        float key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

// 4. Shell Sort
void shellSort(float arr[], int n) {
    for (int gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            float temp = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
    }
}

// Display top 5 scores
void displayTopFive(float arr[], int n) {
    cout << "Top Five Scores: ";
    int count = (n < 5) ? n : 5;
    for (int i = n - 1; i >= n - count; i--) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    float scores[MAX];
    int n, choice;

    inputScores(scores, n);

    while (true) {
        cout << "\n--- Sorting Menu ---\n";
        cout << "1. Selection Sort\n2. Bubble Sort\n3. Insertion Sort\n4. Shell Sort\n5. Display Top Five Scores\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: selectionSort(scores, n);
                    cout << "Sorted using Selection Sort:\n";
                    displayScores(scores, n);
                    break;
            case 2: bubbleSort(scores, n);
                    cout << "Sorted using Bubble Sort:\n";
                    displayScores(scores, n);
                    break;
            case 3: insertionSort(scores, n);
                    cout << "Sorted using Insertion Sort:\n";
                    displayScores(scores, n);
                    break;
            case 4: shellSort(scores, n);
                    cout << "Sorted using Shell Sort:\n";
                    displayScores(scores, n);
                    break;
            case 5: displayTopFive(scores, n);
                    break;
            case 6: cout << "Exiting program.\n";
                    return 0;
            default: cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
