#include<iostream>
#include<cmath>
using namespace std;

const int maxsize = 100;

typedef struct{
    float coef;
    int exp;
}poly_term;

class polynom{
    private :
        poly_term poly[maxsize];
        int total_terms;
    public : 
        polynom(){
            total_terms = 0;
        }
        
        void read_poly(){
            cout << "Enter the no. of total terms : ";
            cin  >> total_terms;
            
            for(int i=0; i<total_terms; i++){
                cout << "Enter the coefficient " << i+1 << " : ";
                cin >> poly[i].coef;
                cout << "Enter the exponent " << i+1 << " : ";
                cin >> poly[i].exp;
            }
        }
        
        void display_poly() {
            for (int i = 0; i < total_terms; i++) {
                cout << poly[i].coef << "x^" << poly[i].exp;
                if (i != total_terms - 1) {
                    cout << " + ";
                }
            }
            cout << endl; 
        }

        void evalulate_poly(double value){
            double result = 0;
            for(int i=0; i<total_terms; i++){
                result += poly[i].coef * pow(value, poly[i].exp);
            }
            cout << "The result of the polynomial is : " << result << endl;
        }

        void add_poly(polynom b){
            polynom c;
            int i = 0, j = 0;

            while (i < total_terms && j < b.total_terms){
                if(poly[i].exp < b.poly[j].exp){
                    c.poly[c.total_terms++] = b.poly[j++];
                }

                else if(poly[i].exp > b.poly[j].exp){
                    c.poly[c.total_terms++] = poly[i++];
                }

                else {
                    c.poly[c.total_terms].exp = poly[i].exp;
                    c.poly[c.total_terms++].coef = poly[i++].coef + b.poly[j++].coef;
                }
            }

            while (i < total_terms){
                c.poly[c.total_terms++] = poly[i++];
            }

            while(j < b.total_terms){
                c.poly[c.total_terms++] = b.poly[j++];
            }

            c.display_poly();
        }

        void mul_poly(polynom b){
            polynom d;

            for(int i=0; i<total_terms; i++){
                for(int j=0; j<b.total_terms; j++){
                    d.poly[d.total_terms].coef = poly[i].coef * b.poly[j].coef;
                    d.poly[d.total_terms++].exp = poly[i].exp + b.poly[j].exp;
                }
            }

            d.display_poly();
        }
};
        

int main(){
    polynom a,b;
    a.read_poly();
    b.read_poly();
    cout << "The first polynomial is : ";
    a.display_poly();
    cout << "The second polynomial is : ";
    b.display_poly();
    cout << "The addition of the two polynomials is : ";
    a.add_poly(b);
    a.evalulate_poly(1);
    cout << "The multiplication of the two polynomials is : ";
    a.mul_poly(b);
    return 0;
}