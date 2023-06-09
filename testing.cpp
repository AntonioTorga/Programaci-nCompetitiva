#include <bits/stdc++.h>
using namespace std;

int main(){

    vector <int> v = {1,2,3,4,5,6,7,8,9,10};
    auto look_for = find(v.begin(), v.end(), 3);
    for (auto it = make_reverse_iterator(look_for); it != v.rend(); it++){
        cout << *it << " ";
    }
    cout << endl;
    // v.insert(v.begin(),look_for,v.end());
    // for (auto it = v.begin(); it != v.end(); it++){
    //     cout << *it << " ";
    // }
}