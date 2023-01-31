#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(9);
    
    int T;
    cin >> T;
    while(T--){
        ll n;
        cin >> n;
        cout << n / 2 + (n % 2) << '\n';
    }

    return 0;
}