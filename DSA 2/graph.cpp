#include <iostream>
using namespace std;

class graph{

private : 
    int a[10][10] = {0};
    int v, e;

public : 

    void read(){

        cout << "Enter the number of vertices : ";
        cin >> v;
        cout << "Enter the number of edges : ";
        cin >> e;

        for(int i = 0; i < e; i++){
            int v1, v2, val;
            cout << "Enter the data as (from 0 to 1 with cost 2 for e.g 0 1 2) : ";
            cin >> v1 >> v2 >> val;

            if(v1 >= v || v2 >= v){
                cout << "Invalid vertex. Must be between 0 and " << v - 1 << endl;
                i--;
                continue;
            }

        a[v1][v2] = val;
        a[v2][v1] = val;
        }

    }

    void display(){
        cout << "Adjacnecy Matrix is : " << endl;
        for(int i = 0; i < v; i++){
            for(int j = 0; j < v; j++){
                cout << a[i][j] << " ";
            }

            cout << endl;
        }
    }

    void isconnection(){
        int v1, v2;
        cout << "Enter the vertices as(fron 0 to 1 for e.g 0 1) : ";
        cin >> v1 >> v2;

        if(v1 >= v || v2 >= v){
            cout << "Invalid vertex. Must be between 0 and " << v - 1 << endl;
            return ;
        }

        if(a[v1][v2] != 0){
            cout << "There is a connection between vertices. " << endl;
            cout << "cost is : " << a[v1][v2] << endl;
        }
        else {cout << "There is no connection between vertices . " << endl;}
    }

};



int main() {

    graph g;
    g.read();
    g.display();
    g.isconnection();
    return 0;

}