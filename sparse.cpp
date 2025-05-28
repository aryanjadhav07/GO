#include <iostream>
using namespace std;

const int MAX = 100;

// Input sparse matrix
void inputSparse(int mat[MAX][3]) {
    cout << "Enter number of rows, columns and non-zero elements: ";
    cin >> mat[0][0] >> mat[0][1] >> mat[0][2];

    cout << "Enter " << mat[0][2] << " elements (row col value):\n";
    for (int i = 1; i <= mat[0][2]; i++) {
        cin >> mat[i][0] >> mat[i][1] >> mat[i][2];
    }
}

// Print sparse matrix
void printMatrix(int mat[MAX][3]) {
    for (int i = 0; i <= mat[0][2]; i++) {
        cout << mat[i][0] << " " << mat[i][1] << " " << mat[i][2] << endl;
    }
}

// Sparse Matrix Addition
void addSparse(int A[MAX][3], int B[MAX][3], int C[MAX][3]) {
    if (A[0][0] != B[0][0] || A[0][1] != B[0][1]) {
        cout << "Addition not possible: dimensions mismatch." << endl;
        return;
    }

    int i = 1, j = 1, k = 1;
    C[0][0] = A[0][0];
    C[0][1] = A[0][1];

    while (i <= A[0][2] && j <= B[0][2]) {
        if (A[i][0] < B[j][0] || (A[i][0] == B[j][0] && A[i][1] < B[j][1])) {
            C[k][0] = A[i][0];
            C[k][1] = A[i][1];
            C[k][2] = A[i][2];
            i++;
        } else if (B[j][0] < A[i][0] || (B[j][0] == A[i][0] && B[j][1] < A[i][1])) {
            C[k][0] = B[j][0];
            C[k][1] = B[j][1];
            C[k][2] = B[j][2];
            j++;
        } else {
            C[k][0] = A[i][0];
            C[k][1] = A[i][1];
            C[k][2] = A[i][2] + B[j][2];
            i++;
            j++;
        }
        k++;
    }

    while (i <= A[0][2]) {
        C[k][0] = A[i][0];
        C[k][1] = A[i][1];
        C[k][2] = A[i][2];
        i++; k++;
    }

    while (j <= B[0][2]) {
        C[k][0] = B[j][0];
        C[k][1] = B[j][1];
        C[k][2] = B[j][2];
        j++; k++;
    }

    C[0][2] = k - 1;
    cout << "Result of Addition:\n";
    printMatrix(C);
}

// Simple Transpose
void simpleTranspose(int A[MAX][3], int B[MAX][3]) {
    B[0][0] = A[0][1];
    B[0][1] = A[0][0];
    B[0][2] = A[0][2];

    int k = 1;
    for (int col = 0; col < A[0][2]; col++) {
        for (int i = 1; i <= A[0][2]; i++) {
            if (A[i][1] == col) {
                B[k][0] = A[i][1];
                B[k][1] = A[i][0];
                B[k][2] = A[i][2];
                k++;
            }
        }
    }

    cout << "Result of Simple Transpose:\n";
    printMatrix(B);
}

// Fast Transpose
void fastTranspose(int A[MAX][3], int B[MAX][3]) {
    int row = A[0][0], col = A[0][1], num = A[0][2];
    int freq[col], startPos[col];

    for (int i = 0; i < col; i++) {
        freq[i] = 0;
        startPos[i] = 0;
    }

    B[0][0] = col;
    B[0][1] = row;
    B[0][2] = num;

    for (int i = 1; i <= num; i++) {
        freq[A[i][1]]++;
    }

    startPos[0] = 1;
    for (int i = 1; i < col; i++) {
        startPos[i] = startPos[i - 1] + freq[i - 1];
    }

    for (int i = 1; i <= num; i++) {
        int pos = startPos[A[i][1]]++;
        B[pos][0] = A[i][1];
        B[pos][1] = A[i][0];
        B[pos][2] = A[i][2];
    }

    cout << "Result of Fast Transpose:\n";
    printMatrix(B);
}

// Main Menu
int main() {
    int A[MAX][3], B[MAX][3], C[MAX][3];
    int choice;

    do {
        cout << "\n---- Sparse Matrix Operations Menu ----\n";
        cout << "1. Sparse Matrix Addition\n";
        cout << "2. Simple Transpose\n";
        cout << "3. Fast Transpose\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Sparse Matrix A:\n";
                inputSparse(A);
                cout << "Enter Sparse Matrix B:\n";
                inputSparse(B);
                addSparse(A, B, C);
                break;

            case 2:
                cout << "Enter Sparse Matrix:\n";
                inputSparse(A);
                simpleTranspose(A, B);
                break;

            case 3:
                cout << "Enter Sparse Matrix:\n";
                inputSparse(A);
                fastTranspose(A, B);
                break;

            case 0:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 0);

    return 0;
}
