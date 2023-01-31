#include<bits/stdc++.h>
#define endl '\n' 
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;

using ll = long long;
using db = long double;
const int maxn = 5e5 + 6;
const ll mod = 1e9 + 7;
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

ll abi_pref[maxn], abi_suf[maxn];
int n;

void upd_pref(int pos, ll val){
    for(pos = pos + 1; pos <= n + 5; pos += pos &-pos)
        abi_pref[pos] = max(abi_pref[pos], val);
}
ll query_pref(int pos){
    ll res = -1e18;
    for(pos = pos + 1; pos > 0; pos -= pos &-pos)
        res = max(res, abi_pref[pos]);
    return res;
}


void upd_suf(int pos, ll val){
    for(pos = pos + 1; pos > 0; pos -= pos &-pos)
        abi_suf[pos] = max(abi_suf[pos], val);
}

ll query_suf(int pos){
    ll res = -1e18;
    for(pos = pos + 1; pos <= n + 5; pos += pos &-pos)
        res = max(res, abi_suf[pos]);
    return res;
}

ll s[maxn], arr[maxn], max_dp[maxn];
ll dp[maxn];

void solve(){

    s[0] = 0;
    vector<ll> aux;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        s[i] = s[i-1] + arr[i];
        aux.push_back(s[i]);
    }
    aux.push_back(0);

    sort(all(aux));
    aux.erase(unique(all(aux)), aux.end());

    fill(abi_pref, abi_pref + n + 6, -1e18);
    fill(abi_suf, abi_suf + n + 6, -1e18);
    fill(max_dp, max_dp + n + 6, -1e18);

    // for(int i = 1; i <= n; i++){
    //     for(int j = 0; j < i; j++){
    //         if(s[j] < s[i]){
    //             dp[i] = max(dp[i], dp[j] + i - j);
    //         }
    //         if(s[j] == s[i]){
    //             dp[i] = max(dp[i], dp[j]);
    //         }
    //         if(s[j] > s[i]){
    //             dp[i] = max(dp[i], dp[j] + j - i);
    //         }
    //     }
    // }


    for(int i = 0; i <= n; i++){
        s[i] = lower_bound(all(aux), s[i]) - aux.begin();
        
        if(i > 0){
            dp[i] = max_dp[s[i]];
            dp[i] = max(dp[i], query_pref(s[i] - 1) + i);
            dp[i] = max(dp[i], query_suf(s[i] + 1) - i);
        }

        upd_pref(s[i], dp[i] - i);
        upd_suf(s[i], dp[i] + i);
    }

    // for(int i = 0; i <= n; i++){
    //     cerr << dp[i] << ' ';
    // }
    // cerr << endl;

    cout << dp[n] << endl;
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