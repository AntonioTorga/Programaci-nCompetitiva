#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct UnionFind{
    vector <int> parent;
    vector <int> sz;

    UnionFind(int n){
        parent.resize(n);
        sz.resize(n,1);
        for (int i = 0; i < n; i++){
            parent[i] = i;
        }
    }
    int find_set(int a){
        if (a == parent[a]) return a;
        // parent[a] = find_set(parent[a]); // Path compression
        // return parent[a];
        return find_set(parent[a]);
    }
    void union_set(int a, int  b){
        a = find_set(a);
        b = find_set(b);
        if (a != b){
            if (sz[a] > sz[b]) swap(a,b);
            parent[a] = b;
            sz[b] += sz[a];
        }
    }
};

int main(){
    int n, m;
    cin >> n >> m;
    UnionFind uf(n);
    int max = 1;
    int comps = n;
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if (uf.find_set(a) != uf.find_set(b)) {
            uf.union_set(a,b);
            comps--;
        }
        if (uf.sz[uf.find_set(a)] > max) max = uf.sz[uf.find_set(a)];
        cout << comps << " " <<  max <<endl;
    }
}