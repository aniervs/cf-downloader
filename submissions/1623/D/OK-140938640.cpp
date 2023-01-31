#include <bits/stdc++.h>
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;

using ll = long long;
using db = long double;
const int maxn = 1e6 + 5;
const ll mod = 1e9 + 7;

ll add(ll x, ll y){ return (x + y >= mod) ? x + y - mod : x + y; }
ll rest(ll x, ll y){ return (x - y + mod) % mod; }
ll mul(ll x, ll y){ return x * y % mod; }
ll qpow(ll b, ll e){
    ll res = 1;
    while(e){
        if(e & 1) res = mul(res, b);
        b = mul(b, b);
        e >>= 1;
    }
    return res;
}
ll inv(ll x){ return qpow(x, mod - 2); }

typedef array<int,4> node; // row, col, dir_row, dir_col

int n, m, rb, cb, rd, cd, p;

int G[maxn];

void solve(){

    cin >> n >> m >> rb >> cb >> rd >> cd >> p;
    p = mul(p, inv(100));

    vector<node> nodes;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            for(int dr : {-1, 1})
                for(int dc : {-1, 1})
                    nodes.push_back({i, j, dr, dc});

    sort(all(nodes));

    int N = nodes.size();

    for(int u = 0; u < N; u++){

        int i = nodes[u][0], j = nodes[u][1], dr = nodes[u][2], dc = nodes[u][3];

        int ndr = dr, ndc = dc;

        if(i + dr < 1 or i + dr > n)
            ndr *= -1;
                    
        if(j + dc < 1 or j + dc > m)
            ndc *= -1;
                    
        int ni = i + ndr;
            int nj = j + ndc;

        G[u] = lower_bound(all(nodes), node{ni, nj, ndr, ndc}) - nodes.begin();
    }

    vector<bool> mark(N);
    vector<ll> prod(N), length(N);

    // int s = lower_bound(all(nodes), node{rb, cb, 1, 1}) - nodes.begin();
    // while(!mark[s]){
    //     cerr << nodes[s][0] << ' ' << nodes[s][1] << ' ' << nodes[s][2] << ' ' << nodes[s][3] << endl;  
    //     mark[s] = 1;
    //     s = G[s];
    // }

    ll cycle_prod = 1, length_cycle = 0;

    int u = lower_bound(all(nodes), node{rb, cb, 1, 1}) - nodes.begin();
    prod[u] = 1;
    length[u] = 0;

    do{
        mark[u] = 1;
        if(!mark[G[u]]){
            if(nodes[u][0] == rd or nodes[u][1] == cd) 
                prod[G[u]] = mul(prod[u], rest(1, p));
            else 
                prod[G[u]] = prod[u];
            length[G[u]] = length[u] + 1;
        }
        u = G[u];
    }while(!mark[u]);

    fill(all(mark), 0);
    do{
        mark[u] = 1;
        if(nodes[u][0] == rd or nodes[u][1] == cd)
            cycle_prod = mul(cycle_prod, rest(1, p));
        length_cycle = add(length_cycle, 1);
        u = G[u];
    }while(!mark[u]);

    ll ans = 0;

    for(int u = 0; u < N; u++){
        if(!mark[u])
            continue;
        if(nodes[u][0] != rd and nodes[u][1] != cd)
            continue;
        ll cur = mul(prod[u], mul(length_cycle, mul(cycle_prod, inv( mul(rest(1, cycle_prod), rest(1, cycle_prod)) ) ) ));
        cur += mul(prod[u], mul(length[u], inv(rest(1,cycle_prod))));
        cur %= mod;
        cur = mul(cur, p);
        ans = add(ans,cur);
    }

    cout << ans << endl;
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int CASOS;
    cin >> CASOS;
    for(int caso = 1; caso <= CASOS; caso++){

        solve();

    }

    return 0;
}