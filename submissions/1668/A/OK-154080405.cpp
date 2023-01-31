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

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0); 

    int CASOS;
    cin >> CASOS;
    for(int caso = 1; caso <= CASOS; caso++){
        ll n, m;
        cin >> n >> m;
        if(min(n, m) == 1 and max(n, m) > 2){
            cout << -1 << endl;
            continue;
        }
        if(min(n,m) == 1){
            if(max(n,m) == 1){
                cout << 0 << endl;
            } else{
                cout << 1 << endl;
            }
            continue;
        }
        ll k = min(n, m);
        ll d = max(n,m) - k;
        ll ans = 2ll * k - 2ll + d + d;
        if(d & 1) ans--;
        cout << ans << endl;

    }

    cerr << endl << "Running time: " << (double)clock()/CLOCKS_PER_SEC << " seconds."<< endl;

    return 0;
}