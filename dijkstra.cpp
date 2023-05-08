#include <bits/stdc++.h>
using namespace std;

long long INF = 1e18;

int main(){
    int n, m;
    cin >> n >> m;


    vector<vector<pair<int, long long>> gr(n);

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
        for (auto [v,w]: adj[u]){
            if(peso_camino+w<dist[v]){
                dist[v] = peso_camino + w;
                prev[v] = u;
                pq.push({dist[v],v});
            }
        }
    }
    if(prev[n-1] == -1){
        cout << "IMPOSSIBLE\n";
    }

    // Si no cout prev hasta q sea igual a 0, cout con el +1

    return 0;
}
