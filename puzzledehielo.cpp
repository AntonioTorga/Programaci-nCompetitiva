#include <bits/stdc++.h>
using namespace std;

int check_unvisited(map < int , bool > visitado){

    for (auto const& x : visitado){
        if (x.second == false) return x.first;
    }
    return -1;
}

int main(){
    int n;
    cin >> n;
    map < int , vector < int > > gr;
    map < int , bool > visitado;
    queue < int > bfs;
    int componentes = 0;
    while(n--){
        int x,y;
        cin >> x >> y;
        y+=1000;
        if (gr.find(x) == gr.end()) gr[x] = vector < int >();
        if (gr.find(y) == gr.end()) gr[y] = vector < int >();
        gr[x].push_back(y);
        gr[y].push_back(x);
        visitado[x] = false;
        visitado[y] = false;
    }
    while(check_unvisited(visitado)!=-1){
        int first = check_unvisited(visitado);
        bfs.push(first);
        visitado[first] = true;
        while(!bfs.empty()){
            int nodo = bfs.front(); bfs.pop();
            for (int vecino: gr[nodo]){
                if(!visitado[vecino]){
                    bfs.push(vecino);
                    visitado[vecino] = true;
                }
            }
        }
        componentes++;
    }
    cout << componentes - 1 << endl; 
}