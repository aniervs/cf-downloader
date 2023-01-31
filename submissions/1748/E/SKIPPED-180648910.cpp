#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const ll mod = 1e9 + 7;
const int maxn = (int)1e6 + 5;

#define all(x) (x).begin(), (x).end()

int n, m, a[maxn];
pair<int,int> st[__lg(maxn) + 1][maxn];

int get_max(int i, int j){
    int k = __lg(j - i + 1);
    pair<int,int> ans = max(st[k][i], st[k][j - (1<<k) + 1]);
    return -ans.second;
}

vector<pair<int,int>> tt;

void dc(int l, int r){
    tt.push_back({l, r});
    if(r - l + 1 < 1) {
        return;
    }
    int p = get_max(l, r);
    dc(l, p - 1);
    dc(p + 1, r);
}

void solve(){

    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    {
        for(int i = 1; i <= n; i++)
            st[0][i] = {a[i], -i};
        for(int j = 1; (1<<j) <= n; j++){
            for(int i = 1; i + (1<<j) - 1 <= n; i++){
                st[j][i] = max(st[j - 1][i], st[j-1][i + (1<<(j-1))]);
            }
        }
    }

    tt.clear();
    dc(1, n);
    map<pair<int,int>, int> id;
    for(int i = 0; i < (int)tt.size(); i++)
        id[tt[i]] = i;
    
    vector<vector<int>> dp((int)tt.size(), vector<int>(m + 1, 0));
    for(int i = (int)tt.size() - 1; i >= 0; i--){
        int l = tt[i].first;
        int r = tt[i].second;
        if(r - l + 1 < 1){
            dp[i][0] = 1;
        } else{
            int p = get_max(l, r);
            int j = id[{l, p - 1}];
            int j2 = id[{p + 1, r}];
            
            for(int t = 1; t <= m; t++){
                dp[i][t] = dp[j][t - 1] * 1ll * dp[j2][t] % mod;
            }
        }
        for(int t = 1; t <= m; t++){
            dp[i][t] += dp[i][t - 1];
            if(dp[i][t] > mod)
                dp[i][t] -= mod;
        }
            
    }
    cout << dp[0][m] << '\n';
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int T;
    cin >> T;
    while(T--){
        solve();
    }
    

    return 0;
}