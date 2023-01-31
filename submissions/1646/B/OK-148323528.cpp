#include<bits/stdc++.h>
#define endl '\n' 
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;

using ll = long long;
using db = long double;
const int maxn = 2e5 + 5;
const ll mod = 1e9 + 7;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

void solve(){

    int n;
    cin >> n;
    vector<ll>a(n);
    for(auto &i:a)
        cin >> i;
    sort(all(a));

    auto s = a, p = a;

    for(int i = n-2; i >= 0; i--){
        s[i] += s[i+1];
    }
    for(int i = 1; i < n; i++){
        p[i] += p[i-1];
    }

    for(int b = 2; b < n; b++){
        int i = b-1;
        int j = n - (b - 1);
        if(p[i] < s[j]){
            cout << "YES" << endl;
            return;
        }
    }   

    cout << "NO" << endl;

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