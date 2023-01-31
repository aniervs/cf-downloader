#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll qpow(ll a, ll b, ll m){
    ll ans = 1;
    while(b){
        if(b & 1)
            ans = ans * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int T;
    cin >> T;
    while(T--){
        ll a, b, d;
        cin >> a >> b >> d;
        int k = __lg(d & -d);
        if(a % (1ll<k) or b % (1ll<<k)){cout << -1 << '\n'; continue;}
        ll c = d / (1ll<<k);
        ll p = (qpow( (c + 1) / 2, 30 - k, c) - 1 + c)%c;
        ll x = (1ll<<30) - (1ll<<k) + p * (1ll<<30);
        cout << x << '\n';
    }

    return 0;
}