#include<iostream>
using namespace std;

#define INF 999
#define N 4

void distanceVector(int graph[N][N]){
    int dist[N][N];
    bool updated;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            dist[i][j] = graph[i][j];
        }
    }

    do{
        updated = false;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                for(int k = 0; k < N; k++){
                    if(dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                        updated = true;
                    }
                }
            }
        }
    }while(updated);

    for(int i = 0; i < N; i++){
        cout << "Distance vector for node : " << i << endl;
        cout << "Distance\tCost" << endl;
        for(int j = 0; j < N; j++){
            if(dist[i][j] == INF){
                cout << j << "\t\t" << INF << endl;
            }
            else{
                cout << j << "\t\t" << dist[i][j] << endl;
            }
        }
    }
}

int main(){
    int graph[N][N] = {
        {0, 2, INF, 1},
        {2, 0, 3, INF},
        {INF, 3, 0, 4},
        {1, INF, 4, 0},
    };

    distanceVector(graph);
}
