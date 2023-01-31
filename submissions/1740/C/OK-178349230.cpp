#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const ll mod = 1e9 + 7;
const int maxn = (int)2e5 + 5;

#define all(x) (x).begin(), (x).end()

int n, a[maxn];

void solve(){

    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);

    ll ans = 0;

    {
        // LRM: R1 + R1 - L2 - M2
        for(int i = 2; i < n; i++){
            ll tmp = a[i + 1]  + a[i + 1] - a[i] - a[1];
            ans = max(ans, tmp);
        }
    }
    {
        // MLR: M1 + R1 - L2 - L2
        for(int i = 1; i < n - 1; i++){
            ll tmp = a[i + 1] - a[i] - a[i] + a[n];
            ans = max(ans, tmp);
        }
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