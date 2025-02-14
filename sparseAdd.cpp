#include<iostream>
using namespace std;

class sparseMat{
private : 
int mat[100][3];

public : 
    void readMat(){
        cout << "Enter the no of rows coloums and non-zero values : ";
        cin >> mat[0][0] >> mat[0][1] >> mat[0][2];

        cout << "Enter the elements : " << endl;
        for(int i = 1 ; i <= mat[0][2]; i++){
            cin >> mat[i][0] >> mat[i][1] >> mat[i][2];
        }

    }

    void displayMat() {
        cout << "Row\tCol\tValue" << endl;
        for (int i = 0; i <= mat[0][2]; i++) {
            cout << mat[i][0] << "\t" << mat[i][1] << "\t" << mat[i][2] << endl;
        }
    }

    sparseMat addSparse(sparseMat b){
        sparseMat c;
        int i = 1, j = 1, k = 1;

        if(mat[0][0] == b.mat[0][0] && mat[0][1] == b.mat[0][1]){
            c.mat[0][0] = mat[0][0];
            c.mat[0][1] = mat[0][1];

            while(i <= mat[0][2] && j <= b.mat[0][2]){
                if(mat[i][0] == b.mat[j][0] && mat[i][1] == b.mat[j][1]){
                    c.mat[k][0] = mat[i][0];
                    c.mat[k][1] = mat[i][1];
                    c.mat[k][2] = mat[i][2] + b.mat[j][2];

                    i++;
                    j++;
                    k++;
                }
                else if(mat[i][0] < b.mat[j][0] || (mat[i][0] == b.mat[j][0] && mat[i][1] < b.mat[j][1])){
                    c.mat[k][0] = mat[i][0];
                    c.mat[k][1] = mat[i][1];
                    c.mat[k][2] = mat[i][2];
                    i++;
                    k++;
                }
                else{
                    c.mat[k][0] = b.mat[j][0];
                    c.mat[k][1] = b.mat[j][1];
                    c.mat[k][2] = b.mat[j][2];
                    j++;
                    k++;
                }
            }

            while(i <= mat[0][2]){
                c.mat[k][0] = mat[i][0];
                c.mat[k][1] = mat[i][1];
                c.mat[k][2] = mat[i][2];
                i++;
                k++;               
            }

            while(j <= b.mat[0][2]){
                c.mat[k][0] = b.mat[j][0];
                c.mat[k][1] = b.mat[j][1];
                c.mat[k][2] = b.mat[j][2];
                j++;
                k++;                
            }
            c.mat[0][2] = k - 1;
        }
        else{
            cout << "The dimensions does not matched.";
            c.mat[0][2] = 0;
        }
        return c;
    }
};


int main(){
    sparseMat a,b,c;
cout << "Enter the Matrix A : ";
    a.readMat();
cout << "Enter the Matrix B : ";
    b.readMat();
cout << "Matrix A : " << endl;
    a.displayMat();
cout << "Matrix B : " << endl;
    b.displayMat();

c = a.addSparse(b);
cout << "The addition of two matrix is : " <<endl;
    c.displayMat();
}