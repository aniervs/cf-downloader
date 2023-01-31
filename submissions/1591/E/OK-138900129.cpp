#include<bits/stdc++.h>
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define lg2(x) __lg(x)
using namespace std;

typedef long long ll;

const int maxn = (int)1e6 + 5;

int cnt[maxn];
int st[maxn<<2];

void upd(int u, int l, int r, int pos, int v){
    if(l == r){
        st[u] += v;
        return;
    }
    int mid = (l + r)>>1;
    if(pos <= mid)
        upd(2*u, l, mid, pos, v);
    else
        upd(2*u + 1, mid + 1, r, pos, v);
    st[u] = st[2*u] + st[2*u + 1];
}
int sum(int u, int l, int r, int L, int R){
    if(l > R or r < L)
        return 0;
    if(l >= L and r <= R)
        return st[u];
    int mid = (l + r)>>1;
    return sum(2*u, l, mid,L,R) + sum(2*u + 1, mid + 1, r, L, R);
}
int find_k(int u, int l, int r, int k){
    if(l == r){
        if(st[u] >= k)
            return l;
        return -1;
    }
    int mid = (l + r)>>1;
    if(st[2*u] >= k)
        return find_k(2*u, l, mid, k);
    return find_k(2*u + 1, mid + 1, r, k - st[2*u]);
}


int p[maxn], a[maxn];
vector<int> G[maxn];

vector<array<int,3>> queries[maxn];
int ans[maxn], n;

multiset<int> nums[maxn];

void dfs(int u){

    if(cnt[a[u]] > 0){
        upd(1, 0, n, cnt[a[u]], -1);
        nums[cnt[a[u]]].erase(nums[cnt[a[u]]].find(a[u]));
    }
    cnt[a[u]]++;
    nums[cnt[a[u]]].insert(a[u]);
    upd(1, 0, n, cnt[a[u]], 1);


    for(auto [i, l, k]:queries[u]){

        int q = sum(1, 0, n, 0, l - 1);
        int f = find_k(1, 0, n, k + q);
        if(f == -1 or nums[f].empty())
            ans[i] = -1;
        else 
            ans[i] = *nums[f].begin();
    }

    for(int v:G[u])
        dfs(v);

    upd(1, 0, n, cnt[a[u]], -1);
    nums[cnt[a[u]]].erase(nums[cnt[a[u]]].find(a[u]));
    cnt[a[u]]--;
    if(cnt[a[u]] > 0){
        nums[cnt[a[u]]].insert(a[u]);
        upd(1, 0, n, cnt[a[u]], 1);
    }
}

void solve(){

    int Q;
    cin >> n >> Q;
    fill(st, st + n * 4 + 3, 0);

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        G[i].clear();
        queries[i].clear();
        cnt[i] = 0;
        nums[i].clear();
    }

    for(int i = 2; i <= n; i++){
        cin >> p[i];
        G[p[i]].push_back(i);
    }

    for(int i = 0; i < Q; i++){
        int v, l, k;
        cin >> v >> l >> k;
        queries[v].push_back({i, l, k});
    }

    dfs(1);

    for(int i = 0; i < Q; i++){
        cout << ans[i] <<  ' ';
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);

    int CASOS;
    cin >> CASOS;
    for(int caso = 1; caso <= CASOS; caso++){
        solve();
    }
    
    return 0;
}