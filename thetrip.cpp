#include <bits/stdc++.h>
using namespace std;

long long INF = 1e18;

int main(){
    int n, m;
    cin >> n >> m ; 
    vector<vector<pair<int, long long>>> adj(2*n);
    while (m--){
        int a, b;
        long long c;
        cin >> a >> b; 
        cin >> c;
        a--; b--;
        adj[a].push_back({b,c});
        adj[a+n].push_back({b+n,c});
        adj[a].push_back({b+n, floor(c/2)});
    }
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    vector <long long> dist (2*n,INF);

    pq.push({0,0});
    dist[0]=0;

    while(!pq.empty()){
        auto [peso_camino, u] = pq.top(); pq.pop();

        if (peso_camino != dist[u]) continue;
        for (auto [v,w]: adj[u]){
            if(peso_camino+w<dist[v]){
                dist[v] = peso_camino + w;
                pq.push({dist[v],v});
            }
        }
    }
    cout << dist[2*n-1] << endl ;
}