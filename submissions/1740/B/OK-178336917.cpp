#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const ll mod = 1e9 + 7;
const int maxn = (int)2e5 + 5;

#define all(x) (x).begin(), (x).end()

int n;
array<int,2> a[maxn];
ll sp[maxn], ss[maxn];

void solve(){
    cin >> n;
    vector<int> all_values;
    int LB = INT_MIN;
    for(int i = 1; i <= n; i++){
        cin >> a[i][0] >> a[i][1];
        if(a[i][0] < a[i][1])
            swap(a[i][0], a[i][1]);
        LB = max(LB, a[i][1]);
        all_values.push_back(a[i][0]);
        all_values.push_back(a[i][1]);
    }
    
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++){
        sp[i] = sp[i - 1] + a[i][1];
    }
    ss[n + 1] = 0;
    for(int i = n; i >= 1; i--){
        ss[i] = ss[i + 1] + a[i][0];
    }

    sort(all(all_values));
    all_values.erase(unique(all(all_values)), all_values.end());

    long long ans = LLONG_MAX;

    for(int x : all_values){
        if(x < LB)
            continue;
        int p = upper_bound(a + 1, a + n + 1, array<int,2>{x, INT_MAX}) - a;
        ll cur_p = 2ll * (x + ss[p] + sp[p - 1]);
        ans = min(ans, cur_p);
    }

    cout << ans << '\n';
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