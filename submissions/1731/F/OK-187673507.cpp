#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)x.size()
using ll = long long;
const ll mod = 998244353;

ll add(ll x, ll y){ return (x + y >= mod) ? x + y - mod : x + y; }
ll rest(ll x, ll y){ return add(x, mod - y); }
ll mul(ll x, ll y){ return x * y % mod; }
ll quick_pow(ll a, ll b){
    ll res = 1;
    while(b){
        if(b & 1)
            res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}
ll inv(ll x){ return quick_pow(x, mod - 2); }

ll ncr[55][55];

int n, k;

ll F(ll x){
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        for(int l = 0; l <= i - 1; l++){
            for(int r = l + 1; r <= n - i; r++){
                ll cur = ncr[i - 1][l];
                cur = mul(cur, quick_pow(rest(x, 1), l));
                cur = mul(cur, quick_pow(rest(k + 1, x), i - 1 - l));
                cur = mul(cur, ncr[n-i][r]);
                cur = mul(cur, quick_pow(rest(k, x), r));
                cur = mul(cur, quick_pow(x, n - i - r));
                ans = add(ans, cur);
            }
        }
    }
    return mul(ans, x);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for(int i = 0; i < 55; i++){
        ncr[i][0] = 1;
        for(int j = 1; j <= i; j++){
            ncr[i][j] = add(ncr[i-1][j], ncr[i-1][j-1]);
        }
    }

    cin >> n >> k;

    vector<ll> x(n + 3), y(n + 3);
    for(int i = 0; i < (int)x.size(); i++){
        x[i] = i + 1;
        y[i] = 0;
        for(int j = 1; j <= x[i]; j++){
            y[i] = add(y[i], F(j));
        }
    }

    if(k < n + 3){
        cout << y[k - 1] << '\n';
        return 0;
    }


    ll ans = 0;
    n = (int)x.size();
    for(int i = 0; i < n; i++){
        ll denominator = 1;
        ll numerator = y[i];
        for(int j = 0; j < n; j++){
            if(j == i){
                continue;
            }
            denominator = mul(denominator, rest(x[i], x[j]));
            numerator = mul(numerator, rest(k, x[j]));
        }
        ans = add(ans, mul(numerator, inv(denominator)));
    }

    cout << ans << '\n';

    return 0;
}