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
vector<pair<ll,ll>> arr;

vector<pair<ll,ll>> st[maxn<<2];

void build(int u, int l, int r){
    if(l == r){
        st[u] = {arr[l]};
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

    st[u].shrink_to_fit();
}
ll ask(const vector<pair<ll,ll>> &v, const pair<ll,ll> &p){
    // cerr << p.first << ": ";
    // for(auto [x, y]:v){
    //     cerr << -x << ' ';
    // }
    // cerr << endl;

    int l = 0, r = (int)v.size() - 1;
    while(l < r){
        int mid = (l + r)>>1;
        auto q = v[mid];
        auto q2 = v[mid + 1];
        if((p.first - q.first) * (p.second - q.second) < (p.first - q2.first) * (p.second - q2.second)){
            l = mid + 1;
        } else{
            r = mid;
        }
    }
    auto q = v[l];
    return (p.first - q.first) * (p.second - q.second);
}

ll query(int u, int l, int r, int L, int R, const pair<ll,ll> a){
    if(l > R or r < L)
        return 0;
    if(l >= L and r <= R)
        return ask(st[u], a);
    int mid = (l + r)>>1;
    return max(query(2*u, l, mid, L, R, a), query(2*u + 1, mid + 1, r, L, R, a));
}

void solve(){

    cin >> n >> m;
    map<int,int> cnt;
    vector<pair<ll,ll>> positive, negative;
    map<int,int> pos;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        cnt[a[i]]++;
    }

    for(auto [x, y]:cnt){
        positive.push_back({x, y});
        negative.push_back({-x, -y});
    }
    sort(all(positive));
    sort(all(negative));
    for(int i = 0; i < (int)negative.size(); i++){
        pos[-negative[i].first] = i;
    }

    arr = negative;

    map<int,vector<int>> bads;

    while(m--){
        int x, y;
        cin >> x >> y;
        for(int i = 0; i < 2; i++){
            bads[x].push_back(pos[y]);
            swap(x, y);
        }
    }

    build(1, 0, (int)negative.size() - 1);

    // for(int u = 1; u <= 10; u++){
    //     cerr << u << ": ";
    //     for(auto [x, y]:st[u]){
    //         cerr << '(' << x << ',' << y << ") ";
    //     }
    //     cerr << endl;
    // }

    ll ans = 0;

    for(auto [x, y]:positive){
        auto bad_positions = bads[x];
        bad_positions.push_back(pos[x]);
        sort(all(bad_positions));

        int l = 0;
        for(int r:bad_positions){
            if(l < r){
                // cerr << '[' << l << ' ' << r <<  "] -- ";
                ans = max(ans, query(1, 0, (int)negative.size() - 1, l, r - 1, pair<ll,ll>{x, y}));
            }
            l = r + 1;
        }
        if(l < (int)negative.size() - 1){
            ans = max(ans, query(1, 0, (int)negative.size() - 1, l, (int)negative.size() - 1, pair<ll,ll>{x, y}));
        }
        // cerr << endl;
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

    cerr << endl << "Running time: " << (double)clock()/CLOCKS_PER_SEC << " seconds."<< endl;

    return 0;
}