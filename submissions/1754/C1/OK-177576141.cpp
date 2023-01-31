#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const ll mod = 1e9 + 7;
const int maxn = (int)2e5 + 5;

#define all(x) (x).begin(), (x).end()

int dp[maxn];

void solve(){

    int n;
    cin >> n;
    vector<int> a(n);
    for(int &i:a)
        cin >> i;
    if(n & 1){
        cout << -1 << '\n';
        return;
    }

    // 1 1 [+1 -1]
    // -1 -1 [-1 +1]
    // 1 -1 [+1] [-1]
    // 
    vector<pair<int,int>> segmn;
    for(int i = 0; i < n; i += 2){
        if(a[i] == a[i + 1]){
            segmn.push_back({i, i + 1});
        } else{
            segmn.push_back({i, i});
            segmn.push_back({i+1, i+1});
        }
    }

    cout << segmn.size() << '\n';
    for(auto [l, r]:segmn){
        cout << l + 1 << ' ' << r + 1<< '\n';
    }
    

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int T;
    cin >> T;
    while(T--){
        solve();
    }

    return 0;
}