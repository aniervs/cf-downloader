#include<bits/stdc++.h>
#define endl '\n' 
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;

using ll = long long;
const int maxn = 3e5 + 5;

int n, m;
vector<pair<ll,ll>> negative;

vector<pair<ll,ll>> st[maxn<<2];

void build(int u, int l, int r){
    if(l == r){
        st[u] = {negative[l]};
        return;
    }
    int mid = (l + r)>>1;
    build(2*u, l, mid);
    build(2*u + 1, mid + 1, r);
    st[u] = st[2*u];
    
    for(auto [x, y]:st[2*u + 1]){
        if(st[u].empty() or st[u].back().second > y){
            st[u].push_back({x, y});
        }
    }
}
ll ask(const vector<pair<ll,ll>> &v, const ll &x, const ll &y){
    int l = 0, r = (int)v.size() - 1;
    while(l < r){
        int mid = (l + r)>>1;
        if((x - v[mid].first) * (y - v[mid].second) < (x - v[mid + 1].first) * (y - v[mid + 1].second)){
            l = mid + 1;
        } else{
            r = mid;
        }
    }
    return (x - v[l].first) * (y - v[l].second);
}

ll query(int u, int l, int r, const int &L, const int &R, const ll &x, const ll &y){
    if(l >= L and r <= R) return ask(st[u], x, y);
    int mid = (l + r)>>1;
    if(mid < L) return query(2*u + 1, mid + 1, r, L, R, x, y);
    if(mid + 1 > R) return query(2*u, l, mid, L, R, x, y);
    return max(query(2*u, l, mid, L, R, x, y), query(2*u + 1, mid + 1, r, L, R, x, y));
}

void solve(){

    cin >> n >> m;
    vector<int> aux, a(n);
    for(auto &i:a){
        cin >> i;
    }
    sort(all(a));
    aux = a;
    aux.erase(unique(all(aux)), aux.end());

    n = aux.size();
    negative.resize(n);
    for(int i = 0; i < n; i++){
        int x = aux[i];
        int y = upper_bound(all(a), x) - lower_bound(all(a), x);
        negative[i] = {-x, -y};
    }

    reverse(all(negative));

    vector<pair<int,int>> bad_pairs(2*m + n);
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        bad_pairs[i] = {x, lower_bound(all(negative), pair<ll,ll>{-y, -(int)1e9}) - negative.begin()};
        bad_pairs[i + m] = {y, lower_bound(all(negative), pair<ll,ll>{-x, -(int)1e9}) - negative.begin()}; 
    }
    for(int i = 0; i < n; i++){
        bad_pairs[2*m + i] = {-negative[i].first, lower_bound(all(negative), pair<ll,ll>{negative[i].first, -(int)1e9}) - negative.begin()};
    }

    sort(all(bad_pairs));

    build(1, 0, n-1);

    ll ans = 0;

    for(auto [x, y]:negative){
        x *= -1, y *= -1;
        int ini = lower_bound(all(bad_pairs), pair<int,int>{(int)x, -1}) - bad_pairs.begin();
        int fin = upper_bound(all(bad_pairs), pair<int,int>{(int)x, 1e9}) - bad_pairs.begin();
        int l = 0;
        for(int i = ini; i < fin; i++){
            int r = bad_pairs[i].second;
            if(l < r) ans = max(ans, query(1, 0, n-1, l, r - 1, x, y));
            l = r + 1;
        }
        if(l < n) ans = max(ans, query(1, 0, n - 1, l, n - 1, x, y));
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0); 

    int CASOS;
    cin >> CASOS;
    for(int caso = 1; caso <= CASOS; caso++){
        solve();
    }

    return 0;
}