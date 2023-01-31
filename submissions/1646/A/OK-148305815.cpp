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

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0); 

    int CASOS;
    cin >> CASOS;
    for(int caso = 1; caso <= CASOS; caso++){
        ll n, s;
        cin >> n >> s;
        ll l = 0, r = min(s / (n * n), n + 1);
        while(l < r){
            ll m = (l + r)>>1;
            if(s - m * n * n > (n - 1ll) * (n + 1 - m))
                l = m + 1;
            else 
                r = m;
        }
        cout << l << endl;
    }

    cerr << endl << "Running time: " << (double)clock()/CLOCKS_PER_SEC << " seconds."<< endl;

    return 0;
}