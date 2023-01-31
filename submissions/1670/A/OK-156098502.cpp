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

        if(neg == 0 or pos == 0){
            auto b = a;
            sort(all(b));
            if(b == a){
                cout << "YES";
            } else{
                cout << "NO";
            }
            cout << endl;
            continue;

        }
        
        bool ans = 1;
        for(int i = 1; i < neg; i++) if(abs(a[i]) > abs(a[i-1])) ans = 0;
        for(int i = neg; i + 1 < n; i++) if(abs(a[i]) > abs(a[i + 1])) ans = 0;

        if(ans) cout << "YES"<< endl;
        else cout << "NO"<< endl;
    }

    cerr << endl << "Running time: " << (double)clock()/CLOCKS_PER_SEC << " seconds."<< endl;

    return 0;
}