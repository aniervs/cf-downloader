#include<bits/stdc++.h>
#define endl '\n' 
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;

using ll = long long;
using db = long double;
const int maxn = 2e5 + 5;
const ll mod = 998244353;

ll add(ll x, ll y){ return (x + y >= mod)?x + y - mod:x + y; }
ll mul(ll x, ll y){ return x * y % mod; }
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

ll cnt[maxn], abi[maxn];
void upd(int pos, int val){
    for(; pos < maxn; pos += pos & -pos)
        abi[pos] = add(abi[pos], val);
}
ll query(int pos){
    ll res = 0;
    for(; pos > 0; pos -= pos & -pos)
        res = add(res, abi[pos]);
    return res;
}

int s[maxn], t[maxn];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0); 

    fact[0] = 1;
    ifact[0] = 1;
    for(int i = 1; i < maxn; i++){
        fact[i] = mul(fact[i-1], i);
        ifact[i] = qpow(fact[i], mod - 2);
    }

    for(int i = 0; i < maxn; i++){
        assert(mul(fact[i], ifact[i]) == 1);
    }
    
    int n, m;
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> s[i];
    for(int i = 1; i <= m; i++)
        cin >> t[i];
   
    for(int i = 1; i <= n; i++){
        cnt[s[i]]++;
        upd(s[i], 1);
    }

    ll ans = 0;
    ll sum = fact[n];
    for(int i = 1; i < maxn; i++)
        sum = mul(sum, ifact[cnt[i]]);

    bool isPrefix = true;
    
    for(int i = 1; i <= min(n, m); i++){
        sum = mul(sum, qpow(n - i + 1, mod - 2));
        ans = add(ans, 
            mul(sum, query(t[i] - 1))
        );
        
        if(cnt[t[i]] == 0){
            isPrefix = false;
            break;
        }

        sum = mul(sum, cnt[t[i]]);
        cnt[t[i]]--;
        upd(t[i], mod-1);
    }

    if(n < m and isPrefix) ans = add(ans, 1);

    cout << ans << endl;


    cerr << endl << "Running time: " << (double)clock()/CLOCKS_PER_SEC << " seconds."<< endl;

    return 0;
}