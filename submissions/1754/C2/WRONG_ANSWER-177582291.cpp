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
    int z = count(all(a), 0);

    if( (n-z) & 1){
        cout << -1 << '\n';
        return;
    }

    // 1 1 [+1 -1]
    // -1 -1 [-1 +1]
    // 1 -1 [+1] [-1]
    // -1 1 [-1] [+1]

    vector<pair<int,int>> segmn;
    int pz = 0;
    while(z < n and a[pz] == 0)
        pz++;
    segmn.push_back({0, pz - 1});
    
    for(int i = pz; i < n; i++){
        if(a[i] == 0){
            segmn.push_back({i, i});
            continue;
        }
        
        int firstNonZero = -1;
        for(int j = i + 1; j < n; j++)
            if(a[j] != 0){
                firstNonZero = j;
                break;
            }

        int t = a[firstNonZero];
        if( (firstNonZero - i) ){
            t *= -1;
        }

        if(a[i] + t == 0){
            segmn.push_back({i, firstNonZero});
        } else{
            segmn.push_back({i, i});
            segmn.push_back({i + 1, firstNonZero});
        }
        i = firstNonZero;
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