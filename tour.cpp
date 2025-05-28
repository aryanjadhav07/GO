#include <iostream>
using namespace std;

const int N = 8;

class KnightsTour {
private:
    int board[N][N];
    int dx[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

public:
    KnightsTour() {
        // Initialize board to -1
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                board[i][j] = -1;

        // Start from top-left corner
        board[0][0] = 0;
    }

    bool isValid(int x, int y) {
        return (x >= 0 && x < N && y >= 0 && y < N && board[x][y] == -1);
    }

    bool solve(int x, int y, int moveCount) {
        if (moveCount == N * N)
            return true;

        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (isValid(nx, ny)) {
                board[nx][ny] = moveCount;

                if (solve(nx, ny, moveCount + 1))
                    return true;

                board[nx][ny] = -1; // backtrack
            }
        }
        return false;
    }

    void displayBoard() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                cout << board[i][j] << "\t";
            cout << endl;
        }
    }

    void start() {
        if (solve(0, 0, 1))
            displayBoard();
        else
            cout << "No solution found." << endl;
    }
};

int main() {
    KnightsTour kt;
    kt.start();
    return 0;
}
