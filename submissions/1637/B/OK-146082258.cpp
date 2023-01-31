#include<bits/stdc++.h>
#define endl '\n' 
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;

using ll = long long;
using db = long double;
const int maxn = 105;

ll a[maxn], dp[maxn];
ll mex[maxn][maxn];

void solve(){

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        vector<bool> mark(n + 5, 0);
        for(int j = i; j <= n; j++){
            if(a[j] <= n + 1) mark[a[j]] = 1;
            for(int k = 0; ; k++){
                if(!mark[k]){
                    mex[i][j] = k;
                    break;
                }
            }
        }
    }   

    ll ans = 0;

    for(int i = 1; i <= n; i++){

        dp[i-1] = 0;
        for(int j = i; j <= n; j++){
            dp[j] = -1e9;
            for(int k = i-1; k < j; k++){
                dp[j] = max(dp[j], dp[k] + mex[k + 1][j] + 1);
            }
            ans += dp[j];
        }

        

    }   

    cout << ans << endl;


    

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