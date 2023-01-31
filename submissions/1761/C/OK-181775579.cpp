#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int maxn = 2e5 + 5;
#define all(x) (x).begin(), (x).end()

void solve(){

    int n;
    cin >> n;
    vector<string> g(n);
    for(string &s:g)
        cin >> s;
    vector<int> indeg(n, 0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(g[i][j] == '1'){
                indeg[j]++;
            }
        }
    }
    queue<int> Q;
    for(int i = 0; i < n; i++)
        if(indeg[i] == 0){
            Q.push(i);
        }
    vector<int> tsort;
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        tsort.push_back(u);
        for(int v = 0; v < n; v++){
            if(g[u][v] == '1'){
                indeg[v]--;
                if(indeg[v] == 0)
                    Q.push(v);
            }
        }
    }

    vector<bitset<100>> dp(n);
    for(int i = 0; i < n; i++){
        dp[i] = 0;
        dp[i].set(i);
    }
    for(int u : tsort){
        for(int v = 0; v < n; v++){
            if(g[u][v] == '1'){
                dp[v] |= dp[u];
            }
        }
    }

    for(int i = 0; i < n; i++){
        cout << dp[i].count() << ' ';
        for(int j = 0; j < n; j++){
            if(dp[i][j]){
                cout << j + 1 << ' ';
            }   
        }
        cout << '\n';
    }

    
    
    


}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(9);
    
    int T;
    cin >> T;
    while(T--){
        solve();

    }

    return 0;
}