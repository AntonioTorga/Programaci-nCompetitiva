#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin >> n;
    ll amount = 0;
    ll sqroot = 0;
    for (ll i = 1; i*i <= n; i++){
        if (n%i == 0) amount += 2;
        if (i*i==n) {
            amount--;
            sqroot = i;
            }
    }
    if (amount%2==0){
        cout << n << " " <<amount/2 << endl;
    }
    else{
        cout << sqroot << " " << amount << endl;
    }
}