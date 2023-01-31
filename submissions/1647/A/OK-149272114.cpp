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
        ll n;
        cin >> n;
        ll x = n / 3;
        if(n % 3 == 0){
            for(int i = 0; i < 2*x; i++){
                if(i & 1) cout << 1;
                else cout << 2;
            }
            cout << endl;
        }
        if(n % 3 == 1){
            for(int i = 0; i < 2*x; i++){
                if(i & 1) cout << 2;
                else cout << 1;
            }
            cout << 1;
            cout << endl;
        }
        if(n % 3 == 2){
            for(int i = 0; i < 2*x; i++){
                if(i & 1) cout << 1;
                else cout << 2;
            }
            cout << 2 << endl;
        }
         
    }

    cerr << endl << "Running time: " << (double)clock()/CLOCKS_PER_SEC << " seconds."<< endl;

    return 0;
}