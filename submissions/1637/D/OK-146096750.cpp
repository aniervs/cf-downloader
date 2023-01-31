#include<bits/stdc++.h>
#define endl '\n' 
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;

using ll = long long;
using db = long double;
const int maxn = 2e5 + 5;

ll dp[105][100 * 100 + 5];
ll a[105], b[105], pref[105];
int n;

void solve(){

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
        cin >> b[i];
    for(int i = 1; i <= n; i++){
        pref[i] = pref[i-1] + a[i] + b[i];
    }

    for(int i = 0; i <= n; i++)
        fill(dp[i], dp[i] + n * 100 + 1, LLONG_MAX);
    dp[0][0] = 0;

    for(int i = 0; i < n; i++){
        for(int A = 0; A <= i * 100; A++){
            if(dp[i][A] == LLONG_MAX)
                continue;
            
            int B = pref[i] - A;
            
            dp[i+1][A + a[i + 1]] = min(dp[i + 1][A + a[i+1]], dp[i][A] + 2ll * (b[i + 1] * (ll) B + a[i + 1] * (ll) A));
            dp[i+1][A + b[i + 1]] = min(dp[i + 1][A + b[i+1]], dp[i][A] + 2ll * (b[i + 1] * (ll) A + a[i + 1] * (ll) B));
        }
    }

    ll ans = LLONG_MAX;
    for(int i = 0; i <= n * 100; i++){
        ans = min(ans, dp[n][i]);
    }

    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            ans += a[i] * a[i] + a[j] * a[j];
            ans += b[i] * b[i] + b[j] * b[j];
        }
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