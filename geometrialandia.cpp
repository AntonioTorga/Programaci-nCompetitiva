#include <bits/stdc++.h>
using namespace std;

int main(){
    long double x_1,y_1,x_2,y_2;
    cin >> x_1 >> y_1 >> x_2 >> y_2;
    long n;
    cin >> n;
    vector<tuple<long double,long double,long double>> rectas;
    while(n--){
        long double a,b,c;
        cin >> a >> b >> c;
        rectas.push_back(make_tuple(a,b,c));
    }
    long double crossed = 0;
    for (auto tupla : rectas){
        long double a,b,c;
        tie(a,b,c) = tupla;
        if (a==0){
            long double y = -c/b;
            if ((y_1 < y && y_2 > y)||(y_1 > y && y_2 < y)){
                crossed++;
            }
        }
        else if (b==0){
            long double x = -c/a;
            if ((x_1 < x && x_2 > x)||(x_1 > x && x_2 < x)){
                crossed++;
            }
        }
        else{
            long double yf1,yf2;
            yf1 = (-a*x_1-c)/(long double)b;
            yf2 = (-a*x_2-c)/(long)b;
            if ((y_1 < yf1 && y_2 > yf2)||(y_1 > yf1 && y_2 < yf2)){
                crossed++;
            }
        }
    }
    cout << crossed << endl;
}