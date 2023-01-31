#include<bits/stdc++.h>
#define endl '\n' 
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;

using ll = long long;
using db = long double;
const int maxn = 1e6 + 5;
const ll mod = 1e9 + 7, inv2 = 5e8 + 4;
ll add(ll a, ll b){ return (a + b >= mod)?a + b - mod:a + b;}
ll rest(ll a, ll b){ return add(a, mod - b);}
ll mul(ll a, ll b){ return a * b % mod; }
ll qpow(ll a, ll b){
    ll res = 1;
    while(b){
        if(b & 1)
            res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

ll fact[maxn], ifact[maxn];

ll ncr(int n, int k){
    if(n < k or k < 0) return 0;
    return mul(fact[n], mul(ifact[k], ifact[n-k]));
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0); 

    fact[0] = 1;
    for(int i = 1; i < maxn; i++)
        fact[i] = mul(fact[i-1], i);
    ifact[maxn-1] = qpow(fact[maxn-1], mod - 2);
    for(int i = maxn-2; i >= 0; i--)
        ifact[i] = mul(i + 1, ifact[i + 1]);
    
    for(int i = 0; i < maxn; i++)
        assert(mul(fact[i], ifact[i]) == 1);

    int CASOS;
    cin >> CASOS;
    for(int caso = 1; caso <= CASOS; caso++){
        int n, m, k;
        cin >> n >> m >> k;


        ll ans = 0;
        for(int i = 1; i <= m; i++){
            int j = m - i;
            ll tmp = i + 1;
            tmp = mul(tmp, ncr(n - i, j));
            tmp = mul(tmp, qpow(inv2, n-i));
            tmp = mul(tmp, k);
            tmp = mul(tmp, inv2);
            ans = add(ans, tmp);
        }

        cout << ans << endl;
    }

    cerr << endl << "Running time: " << (double)clock()/CLOCKS_PER_SEC << " seconds."<< endl;

    return 0;
}