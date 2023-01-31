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
        int n;
        cin >> n;
        vector<int> a(n);
        int pos = 0, neg = 0;
        for(auto &i:a){
            cin >> i;
            if(i > 0) pos++;
            else neg++;
        }
        vector<bool> suf_ok(n, 0), pref_ok(n, 0);
        for(int i = 0; i < n; i++){
            if(i == 0 or (pref_ok[i-1] and abs(a[i-1]) >= abs(a[i])))
                pref_ok[i] = 1;
        }
        for(int i = n - 1; i >= 0; i--){
            if(i == n - 1 or (suf_ok[i+1] and abs(a[i + 1]) >= abs(a[i])))
                suf_ok[i] = 1;
        }
        

        if(suf_ok[0] or pref_ok[n-1]){
            cout << "YES" << endl;
            continue;
        }
        if(neg > 0 and pos > 0){
            if(pref_ok[neg - 1] and suf_ok[neg])
                cout << "YES"<< endl;
            else cout << "NO"<< endl;
        } else{
            cout << "NO" << endl;
        }
    }

    cerr << endl << "Running time: " << (double)clock()/CLOCKS_PER_SEC << " seconds."<< endl;

    return 0;
}