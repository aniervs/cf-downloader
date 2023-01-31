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

        int n; ll m;
        cin >> n >> m;
        vector<ll> a(n);
        for(auto &i:a)
            cin >> i;
        sort(all(a));
        ll s = 0;
        for(int i = 1; i < n; i++)
            s += a[i];
        if(s + a[n-1] + n <= m){
            cout << "YES";
        } else{
            cout << "NO";
        }
        cout << endl;
        
    }

    cerr << endl << "Running time: " << (double)clock()/CLOCKS_PER_SEC << " seconds."<< endl;

    return 0;
}