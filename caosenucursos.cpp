#include <bits/stdc++.h>
using namespace std;

int check_unvisited(vector < bool > visitado){
    for ( int i = 0 ; i < visitado.size() ; i++){
        if (visitado[i] == false) return i;
    }
    return -1;
}
int main(){
    int n,m;
    cin >> n >> m;
    vector < set <int> > gr(n+1);
    vector <bool> visitado(n+1, false);
    queue <int> bfs;
    vector <int> tam, rep(n+1);
    int groups = 0;

    while(m--){
        int k;
        cin >> k;
        vector <int> members(k);
        while(k--){
            int mem;
            cin >> mem;
            for (int m : members){
                gr[mem].insert(m);
                
            }
            members.push_back(mem);
        }
    }
    visitado[0] = true;
    while(check_unvisited(visitado)!=-1){
        int temp = check_unvisited(visitado);
        bfs.push(temp);
        rep[temp] = groups;
        tam.push_back(0);
        visitado[temp] = true;

        while(!bfs.empty()){
            int nodo = bfs.front(); bfs.pop();
            for (int vecino: gr[nodo]){
                bfs.push(vecino);
                visitado[vecino] = true;
                rep[vecino] = rep[nodo];
                tam[rep[vecino]]++;
            }
        }
        groups++;
    }
    for(int i = 1; i<n+1; i++){
       cout << tam[rep[i]] << " ";
    }
}