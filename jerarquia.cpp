#include <bits/stdc++.h>
using namespace std;

struct UnionFind{
    vector <int> parent;
    vector <int> sz;

    UnionFind(int n){
        parent.resize(n);
        sz.assign(n,1);
        for (int i= 0; i < n; i++ ){
            parent[i] = i;
        }
    }
    int find_set(int node){
        if (parent[node] == node) return node;
        parent[node] = find_set(parent[node]);
        return parent[node];
    }
    void union_set(int node1, int node2){
        node1 = find_set(node1);
        node2 = find_set(node2);
        if (node1!=node2){
            if (sz[node1] > sz[node2]){
                swap(node1,node2);
            }
            parent[node1] = node2;
            sz[node2] += sz[node1];
        }
    }
};
   

int kruskal(int n, vector<tuple<int,int,int>> &edges, vector<bool>& rel){
    UnionFind dsu(n);
    sort(edges.begin(),edges.end());

    int ans= 0;
    for( auto [w,u,v] : edges){
        if(dsu.find_set(u) != dsu.find_set(v) && !rel[v]){
            ans += w;
            dsu.union_set(u,v);
            rel[v] = true;
        }
    }
    return ans;
}

int main(){
    int  n, m; 
    cin >> n;
    vector<bool> rel(n,false);
    int n_c = n;
    while(n_c--){
        int q_i;
        cin >> q_i;
    }
    cin >> m;
    vector<tuple<int,int,int>> edges(m);
    for(int i = 0; i < m ; i++){
        int a,b,c;
        cin >> a >> b >> c;
        a--;
        b--;
        edges[i] = {c,a,b};
        }

    int res = kruskal(n, edges, rel);
    if(count(rel.begin(), rel.end(), false) != 1) cout << -1 << endl;
    else { cout << res << endl; }
}
