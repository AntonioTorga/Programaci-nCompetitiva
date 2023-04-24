#include <bits/stdc++.h>
using namespace std;
void BFS (int start_node ,vector<vector<int>>& gr, vector<bool>& visitado, vector<int>& tam, vector<int>& rep){
    queue <int> bfs;   
    visitado[start_node] = true;
    tam[start_node]=1;
    rep[start_node]=start_node;
    bfs.push(start_node);

    while(!bfs.empty()){
        int nodo = bfs.front(); bfs.pop();
        for (int vecino: gr[nodo]){
                if(!visitado[vecino]){
                    bfs.push(vecino);
                    visitado[vecino] = true;
                    rep[vecino] = start_node;
                    tam[start_node]++;
                }
        }
    }
}
int main(){
    int n,m;
    cin >> n >> m;
    vector < vector <int> > gr(n+1);
    vector <bool> visitado(n+1, false);
    visitado[0] = true;
    vector <int> tam(n+1, 0), rep(n+1);
    
    while(m--){
        int k;
        cin >> k;
        int prev = -1;
        while(k--){
            int elem;
            cin >> elem;
            if (prev!=-1){
                gr[elem].push_back(prev);
                gr[prev].push_back(elem);
            }
            prev = elem;
        }
    }
    for (int i = 1; i < n+1; i++){
        if (!visitado[i]){
            BFS(i, gr, visitado, tam, rep);
        }
    }

    for(int i = 1; i<n+1; i++){
       cout << tam[rep[i]] << " ";
    }
}