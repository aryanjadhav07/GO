#include <iostream>
using namespace std;

class graph{

private : 
    int a[10][10] = {0};
    int v, e;
    string city[10];

public : 

    void read(){

        cout << "Enter the number of cities : ";
        cin >> v;

        cout << "Enter the names of cities : " << endl;
        for(int i = 0; i < v; i++){
            cout << "City " << i + 1 << " : ";
            cin >> city[i];
        }

        cout << "Enter the number of flights : ";
        cin >> e;

        for(int i = 0; i < e; i++){
            string c1, c2 ;
            int val;
            cout << "Enter the data as (from city1 to city2 with cost 2 for e.g nashik pune 200) : ";
            cin >> c1 >> c2 >> val;

            int indx1 = getCityIndx(c1);
            int indx2 = getCityIndx(c2);

            if(indx1 >= v || indx2 >= v){
                cout << "Invalid city name entered." << endl;
                i--;
                continue;
            }

        a[indx1][indx2] = val;
        a[indx2][indx1] = val;
        }

    }

    int getCityIndx(string cname){
        for(int i = 0; i < v; i++){
            if(city[i] == cname){
                return i;
            }
        }
        return -1;
    }

    void display(){
        cout << "Adjacnecy Matrix is : " << endl;
        for(int i = 0 ; i < v; i++){
            cout << city[i] << " ";
        }
        cout << endl;
        for(int i = 0; i < v; i++){
            cout << city[i] << " ";
            for(int j = 0; j < v; j++){
                cout << a[i][j] << " ";
            }
            cout << endl;
        }

    }


    void isconnection(){
        string v1, v2;
        cout << "Enter the vertices as(fron nashik to pune for e.g nashik pune) : ";
        cin >> v1 >> v2;

            int indx1 = getCityIndx(v1);
            int indx2 = getCityIndx(v2);

        if(indx1 == -1 || indx2 == -1){
            cout << "Invalid city name entered." << endl;
            return ;
        }

        if(a[indx1][indx2] != 0){
            cout << "There is a connection between vertices. " << endl;
            cout << "cost is : " << a[indx1][indx2] << endl;
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