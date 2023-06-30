#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin >> n;
    ll i = 1;
    ll res=0;
    ll th = pow(10,9)+7;
    while(i <= n){
        ll q = floor(n/i);
        ll f = floor(n/q);
        res += (((f*(f+1) - (i-1)*i)/2)*q)%th;
        i = f+1;
    }
    cout << res%th << endl;
}