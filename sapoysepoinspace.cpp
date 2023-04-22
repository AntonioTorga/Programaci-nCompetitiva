#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m; 
    cin >> n >> m;
    //contenedor del grafo
    vector< vector<int> > gr(n+1);
    //para recorrido bfs
    vector<bool> visitado(n+1,false);
    vector<int> distancia(n+1);
    vector< vector<int> > camino(n+1);
    queue<int> bfs;
    
    //guardamos el grafo

    while(m--){
        int u, v;
        cin >> u >> v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    // hagamos un recorrido BFS y para cada iteración guardamos al nodo en una lista entregada por el nodo
    // padre, esto puede complicarse por la cantidad de memoria.

    //empezamos por cero por lo que lo ingresamos a la cola y lo seteamos como visitado.
    bfs.push(1);
    visitado[1] = true;
    distancia[1] = 0;
    camino[1].push_back(1);
    bool found = false; //encontramos o no un camino desde 0 hasta n-1
    while(!bfs.empty()){
        int nodo = bfs.front(); bfs.pop();
        if (nodo == n){
            found=true;
            cout << distancia[nodo] + 1 << endl; // +1 porque la cantidad de nodos visitados es la distancia +1
            for(int planet:camino[nodo]) cout << planet << " ";
            break;
            }
        for (int vecino: gr[nodo]){
            if (!visitado[vecino]){
                bfs.push(vecino);
                distancia[vecino] = distancia[nodo] + 1;
                camino[vecino] = camino[nodo];
                camino[vecino].push_back(vecino);
                visitado[vecino] = true;
            }
        }
    }
    if (!found) {
        cout << "IMPOSSIBLE" << endl;
    }
}

