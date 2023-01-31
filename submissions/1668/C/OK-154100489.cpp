#include<bits/stdc++.h>
#define endl '\n' 
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;

using ll = long long;
using db = long double;
const int maxn = 2e5 + 5;
const ll mod = 1e9 + 7;
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

ll a[maxn], b[maxn];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0); 

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    ll ans = LLONG_MAX;

    for(int i = 1; i <= n; i++){
        ll cur = 0;
        fill(b + 1, b + n + 1, 0);
        for(int j = i + 1; j <= n; j++){
            ll k = b[j - 1] / a[j] + 1;
            cur += k;
            b[j] = a[j] * k;
        }
        for(int j = i - 1; j >= 1; j--){
            ll k = (-b[j + 1])/a[j] + 1;
            cur += k;
            b[j] = -a[j] * k;
        }
        ans = min(ans, cur);
    }

    cout << ans << endl;


    cerr << endl << "Running time: " << (double)clock()/CLOCKS_PER_SEC << " seconds."<< endl;

    return 0;
}