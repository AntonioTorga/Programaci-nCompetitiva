#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector <int> per;
        per.push_back(0);
        unordered_set <int> dist;
        int n_c = n;
        while(n_c--){
            int elem;
            cin >> elem;
            per.push_back(elem);
        }
        for (int i = 1; i < n+1; i++){
            int num = abs(per[i] - i);
            if (num == 0) continue;
            dist.insert(num);
        }
        int ans = *max_element(dist.begin(), dist.end());
        for (auto elem:dist){
            ans = gcd(ans, elem);
        }
        cout << ans << endl;
    }
}