#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m; 
    cin >> n >> m;
    //contenedor del grafo
    vector< vector<int> > gr(n+1);
    //para recorrido bfs
    vector<int> parents(n+1,-1);
    vector<int> distancia(n+1); 
    queue<int> bfs;

    //guardamos el grafo

    while(m--){
        int a, b;
        cin >> a >> b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    // hagamos un recorrido BFS y para cada iteración guardamos al nodo en una lista entregada por el nodo
    // padre, esto puede complicarse por la cantidad de memoria.
    //empezamos por cero por lo que lo ingresamos a la cola y lo seteamos como visitado.

    bfs.push(1);
    distancia[1] = 0;

    parents[1] = 1;
    bool found = false; //encontramos o no un camino desde 0 hasta n-1
    while(!bfs.empty()){
        int nodo = bfs.front(); bfs.pop();
        if (nodo == n){
            found=true;
            vector<int>  ancestors;
            int daddy = nodo, count = 1;
            ancestors.push_back(daddy);
            while(daddy!=1){
                daddy = parents[daddy];
                ancestors.insert(ancestors.begin(), daddy);
                count++;
            }
            cout << count << endl; 
            for (int planet : ancestors) cout << planet << " ";
            break;
            }
        for (int vecino: gr[nodo]){
            if (parents[vecino] == -1){
                bfs.push(vecino);
                distancia[vecino] = distancia[nodo] + 1;
                parents[vecino] = nodo;
            }
        }
    }
    if (!found) {
        cout << "IMPOSSIBLE" << endl;
    }
}