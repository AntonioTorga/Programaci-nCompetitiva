#include <bits/stdc++.h>
using namespace std;
int main(){
    int N,K;
    cin>>N>>K;
    int var = N;
    vector<pair<long long, long long>> estrellas;
    vector<bool> false_vec(N,false);
    vector<vector<bool>> visitado(N,false_vec);

    while(var--){
        long long x,y;
        cin>>x>>y;
        estrellas.push_back(make_pair(x,y));
    }
    if (K==1){
        cout<<"Infinity"<<endl;
        return 0;
    }
    long long res = 0;
    for (int i = 0; i<N; i++){
        for (int j = i + 1; j<N; j++){
            if (visitado[i][j]) continue;
            // TOMAMOS DOS PUNTOS PARA DEFINIR LA RECTA
            long long x_p, y_p, x_q, y_q,x_r,y_r;
            x_p = estrellas[i].first;
            y_p = estrellas[i].second;
            x_q = estrellas[j].first;
            y_q = estrellas[j].second;

            double lhs_const = x_p-x_q;
            double rhs_const = y_p-y_q;

            unordered_set<int> in_recta;
            in_recta.insert(i);
            in_recta.insert(j);
            for(int m = 0; m<N; m++){
                // REVISAMOS CADA ESTRELLA PARA VER SI ESTA EN LA RECTA
                if (in_recta.count(m)) continue;
                x_r = estrellas[m].first;
                y_r = estrellas[m].second;
                double lhs = (y_r-y_p)*lhs_const;
                double rhs =  (x_r-x_p)*rhs_const;
                if (lhs == rhs){
                    in_recta.insert(m);
                }
            }
            int stars_in_line = in_recta.size();
            if (stars_in_line >= K){
                // si esta estrellada
                res++;
            }
            
            for(auto it = in_recta.begin(); it!=in_recta.end();  it++){
                for(auto jt = next(it); jt!=in_recta.end(); jt++){
                    int i = *it;
                    int j = *jt;
                    visitado[i][j] = true;
                    visitado[j][i] = true;
                }
            }
        }
    }
    cout<<res<<endl;
}