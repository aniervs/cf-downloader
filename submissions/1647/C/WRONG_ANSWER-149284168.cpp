#include<bits/stdc++.h>
#define endl '\n' 
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;

using ll = long long;
using db = long double;
const int maxn = 2e5 + 5;
const ll mod = 1e9 + 7;

void solve(){

    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for(auto &s:a)
        cin >> s;
    if(a[0][0] != '0'){cout << -1 << endl; return;}
    vector<array<int,4>> ans;
    for(int r = n - 1; r >= 0; r--){
        for(int c = m - 1; c >= 0; c--){
            if(a[r][c]=='1'){
                if(r > 0){
                    ans.push_back({r-1, c, r, c});
                } else{
                    ans.push_back({r, c - 1, r, c});
                }
            }
        }
    }

    cout << ans.size() << endl;
    for(auto t:ans){
        for(int i = 0; i < 4; i++){
            cout << t[i] << ' ';
        }
        cout << endl;
    }


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