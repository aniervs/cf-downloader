#include<bits/stdc++.h>
#define endl '\n' 
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;

using ll = long long;
using db = long double;
const int maxn = 3e5 + 5;

int n, m;
ll a[maxn];
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
        auto q = v[mid];
        auto q2 = v[mid + 1];
        if((x - q.first) * (y - q.second) < (x - q2.first) * (y - q2.second)){
            l = mid + 1;
        } else{
            r = mid;
        }
    }
    auto q = v[l];
    return (x - q.first) * (y - q.second);
}

ll query(int u, int l, int r, int L, int R, const ll &x, const ll &y){
    if(l > R or r < L)
        return 0;
    if(l >= L and r <= R)
        return ask(st[u], x, y);
    int mid = (l + r)>>1;
    return max(query(2*u, l, mid, L, R, x, y), query(2*u + 1, mid + 1, r, L, R, x, y));
}

void solve(){

    cin >> n >> m;
    map<int,int> cnt;
    negative.clear();
    map<int,int> pos;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        cnt[a[i]]++;
    }

    for(auto [x, y]:cnt){
        negative.push_back({-x, -y});
    }

    reverse(all(negative));
    n = negative.size();

    for(int i = 0; i < n; i++){
        pos[-negative[i].first] = i;
    }

    map<int,vector<int>> bads;

    while(m--){
        int x, y;
        cin >> x >> y;
        bads[x].push_back(pos[y]);
        bads[y].push_back(pos[x]);
    }

    build(1, 0, n-1);

    ll ans = 0;

    reverse(all(negative));

    for(auto [x, y]:negative){
        x *= -1, y *= -1;
        auto bad_positions = bads[x];
        bad_positions.push_back(pos[x]);
        sort(all(bad_positions));
        int l = 0;
        for(int r:bad_positions){
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