#include <iostream>
#include <random>

using namespace std;

const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

struct Cockroach {
    int x, y, moves = 0;
    int rows, cols;
    bool** visited;
    mt19937 rng; 
    uniform_int_distribution<int> dirDist;

    Cockroach(int n, int m) 
        : rows(n), cols(m), rng(random_device{}()), dirDist(0, 7) {

        visited = new bool*[rows];
        for (int i = 0; i < rows; i++) {
            visited[i] = new bool[cols](); 
        }

        x = m / 2;
        y = n / 2;
        visited[y][x] = true; 
    }

    
    bool allVisited() {
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                if (!visited[i][j]) return false;
        return true;
    }

    void move() {
        while (!allVisited()) {
            int dir = dirDist(rng); 
            int newX = x + dx[dir];
            int newY = y + dy[dir];

     
            if (newX >= 0 && newX < cols && newY >= 0 && newY < rows) {
                x = newX;
                y = newY;
                visited[y][x] = true;
                moves++;
            }
        }
    }

    ~Cockroach() {
        for (int i = 0; i < rows; i++) {
            delete[] visited[i];
        }
        delete[] visited;
    }
};

int main() {
    int n, m;
    cout << "Enter grid size (rows cols): ";
    cin >> n >> m;

    if (n <= 0 || m <= 0) {
        cout << "Invalid grid size!" << endl;
        return 1;
    }

    Cockroach bug(n, m);
    bug.move(); 

    cout << "Total moves taken: " << bug.moves << endl;
    return 0;
}