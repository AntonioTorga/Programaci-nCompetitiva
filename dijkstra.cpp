#include <bits/stdc++.h>
using namespace std;

long long INF = 1e18;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, long long>>> gr(n);

    while (m--){
        int u,v;
        long long w;

        cin >> u >> v;
        cin >> w;

        u--;
        v--;
        gr[u].push_back({v,w});
        gr[v].push_back({u,w});
    }

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    vector <long long> dist (n,INF);
    vector <int> prev(n,-1);
    
    pq.push({0,0});
    prev[0] = 0;
    dist[0]=0;

    while(!pq.empty()){
        auto [peso_camino, u] = pq.top(); pq.pop();

        if (peso_camino != dist[u]) continue;
        for (auto [v,w]: gr[u]){
            if(peso_camino+w<dist[v]){
                dist[v] = peso_camino + w;
                prev[v] = u;
                pq.push({dist[v],v});
            }
        }
    }
    vector <int> res;

    if(prev[n-1] == -1){
        res.push_back(-1);
    }

    else{
        res.push_back(n);
        int pr = n-1;
        while (pr!=0){
            res.push_back(prev[pr]+1);
            pr = prev[pr];
        }
    }
    for(auto it= res.rbegin(); it!= res.rend();it++){
        cout << *it << " ";
    }

    return 0;
}
