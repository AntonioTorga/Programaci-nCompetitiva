#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m,k;
    cin >> n >> m >> k;
    vector< vector <char> > gr(n);
    vector< vector <bool> > visitado(n);
    queue< pair <int , int> > bfs;
    pair <int , int> start(-1,-1) , comp(-1,-1);
    int num = 0;
    for(int i = 0; i<n; i++){ //filas
        string pp;
        cin >> pp;
        for(int j = 0; j<m; j++){ //columnas
            if (pp[j] == '.') {
                if (start == comp) start = make_pair(i,j);
                num++;
                }
            gr[i].push_back(pp[j]);
            visitado[i].push_back(false);
        }
    } // ahora num es igual a los espacios vacios
    num = num - k; //cantidad de espacios que terminan vacios
    bfs.push(start);
    visitado[start.first][start.second] = true;

    while(!bfs.empty()){
        pair <int , int> nodo = bfs.front(); bfs.pop(); 
        if (nodo.first != n-1 and gr[nodo.first + 1][nodo.second] == '.' and !visitado[nodo.first + 1][nodo.second]){ //vecino de abajo
            bfs.push(make_pair(nodo.first + 1,nodo.second));
            visitado[nodo.first + 1][nodo.second] = true;
            if (num>1) num--; //restamos para llevar conteo de los espacios libres que quedan por dejar
            else {gr[nodo.first + 1][nodo.second] = 'X';}
        }
        if (nodo.first != 0 and gr[nodo.first - 1][nodo.second] == '.' and !visitado[nodo.first - 1][nodo.second]){ //vecino de arriba
            bfs.push(make_pair(nodo.first - 1,nodo.second));
            visitado[nodo.first - 1][nodo.second] = true;
            if (num>1) num--; //restamos para llevar conteo de los espacios libres que quedan por dejar
            else {gr[nodo.first - 1][nodo.second] = 'X';}
        }
        if (nodo.second != m-1 and gr[nodo.first][nodo.second + 1] == '.' and !visitado[nodo.first][nodo.second + 1]){ //vecino de derecha
            bfs.push(make_pair(nodo.first,nodo.second + 1));
            visitado[nodo.first][nodo.second + 1] = true;
            if (num>1) num--; //restamos para llevar conteo de los espacios libres que quedan por dejar
            else {gr[nodo.first][nodo.second + 1] = 'X';}
        }
        if (nodo.second != 0 and gr[nodo.first][nodo.second - 1] == '.' and !visitado[nodo.first][nodo.second - 1]){ //vecino de izquierda
            bfs.push(make_pair(nodo.first,nodo.second - 1));
            visitado[nodo.first][nodo.second - 1] = true;
            if (num>1) num--; //restamos para llevar conteo de los espacios libres que quedan por dejar
            else {gr[nodo.first][nodo.second - 1] = 'X';}
        }
    }
    for(int i = 0; i<n; i++){ //filas
        for(int j = 0; j<m; j++){ //columnas
            cout << gr[i][j];
        }
        cout << "\n";
    }
}