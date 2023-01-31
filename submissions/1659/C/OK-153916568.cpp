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

ll arr[maxn], s[maxn];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0); 

    int CASOS;
    cin >> CASOS;
    for(int caso = 1; caso <= CASOS; caso++){
        int n;
        ll a, b; 
        cin >> n >> a >> b;
        for(int i = 1; i <= n; i++){
            cin >> arr[i];
        }    
        s[n+1] = 0;
        for(int i = n; i >= 1; i--)
            s[i] = s[i + 1] + arr[i];
        
        ll ans = s[1] * b;

        for(int i = 1; i <= n; i++){
            ans = min(ans, 
                arr[i] * b + arr[i] * a + (s[i + 1] - arr[i] * (ll)(n - i)) * b
            );
        }
        cout << ans << endl;
    }

    cerr << endl << "Running time: " << (double)clock()/CLOCKS_PER_SEC << " seconds."<< endl;

    return 0;
}