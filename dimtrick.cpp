#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector <pair <bool,int>> criba(int n){
    vector <pair <bool,int>> es_primo(n+1,{true,0}); 
    es_primo[0] = es_primo[1] = {false,0};
    for (int i = 2; i*i <= n; i++){
        if (es_primo[i].first){
            es_primo[i] = {true,0};
            for (int j = i*i; j <= n; j += i){
                es_primo[j] = {false,0};
            }
        }
    }
    return es_primo;
}
int main(){
    int T;
    cin >> T;
    vector <pair<ll,ll>> v;
    int tries = T;
    while (tries--){        
        ll N,K;
        cin >> N >> K;
        v.push_back(make_pair(N,K));
    }
    vector <pair <bool,int>> es_primo = criba(100000);
    int max_check = 0;
    for (int i = 0; i < T; i++){
        ll N = v[i].first;
        ll K = v[i].second;
        long double sqK = sqrt(K);
        long double sqN = sqrt(N);
        ll total = 0;
        ll res = 0;
        for (int j = 0; j < ceil(sqN);j++){
            if (es_primo[j].first) {
                total++;
                if (max_check < i) max_check = i;
                if (sqK < j) res++;
            }
            es_primo[j].second = total;
        }
        cout << total << " " << res << endl;
    }
}