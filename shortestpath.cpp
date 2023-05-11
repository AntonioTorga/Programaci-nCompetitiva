#include <bits/stdc++.h>
using namespace std;

long long INF = 1e18;

int main(){
    while(true){
        int N, M;
        cin >> N >> M;
        if (N==0 && M==0) {
            return 0;
            }
        int S, D;
        cin >> S >> D;

        vector<vector<pair<int, long long>>> adjS(N);
        vector<vector<pair<int, long long>>> adjD(N);
        vector<vector<pair<int, long long>>> adjFin(N);

        while (M--){
            int U,V,P;
            cin >> U >> V >> P;
            adjS[U].push_back({V,P});
            adjD[V].push_back({D,P});
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        vector <long long> distS (N,INF);
        vector <long long> distD (N,INF);
        vector <long long> distFin (N,INF);

        pq.push({S,0});
        distS[0]=0;

        while(!pq.empty()){
            auto [peso_camino, u] = pq.top(); pq.pop();
            if (peso_camino != distS[u]) continue;
            for (auto [v,w]: adjS[u]){
                if(peso_camino+w<distS[v]){
                    distS[v] = peso_camino + w;
                    pq.push({distS[v],v});
                }
            }
        }

        pq.push({D,0});
        distD[0]=0;

        while(!pq.empty()){
            auto [peso_camino, u] = pq.top(); pq.pop();
            if (peso_camino != distD[u]) continue;
            for (auto [v,w]: adjD[u]){
                if(peso_camino+w<distD[v]){
                    distD[v] = peso_camino + w;
                    pq.push({distD[v],v});
                }
            }
        }
        
        for (int i = 0; i < N; i++){
            auto itr = adjFin[i].begin();
            for (int j = 0; j < adjS[i].size(); i++){
                auto [node, peso] = adjS[i][j];
                if (distS[i] + peso + distD[node] != distS[D]){ adjFin[i].push_back(make_pair(node,peso)); }
            }
        }

        pq.push({S,0});
        distFin[0]=0;
        while(!pq.empty()){
            auto [peso_camino, u] = pq.top(); pq.pop();
            if (peso_camino != distFin[u]) continue;
            for (auto [v,w]: adjFin[u]){
                if(peso_camino+w<distFin[v]){
                    distFin[v] = peso_camino + w;
                    pq.push({distFin[v],v});
                }
            }
        }
        cout << distFin[D] << endl;
    }
}