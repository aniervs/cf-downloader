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

const int MAXX = (1<<__lg(5000)) + 1;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cout.setf(ios::fixed); cout.precision(0);

    int T;
    cin >> T;
    while(T--){

        int n;
        cin >> n;
        vector<int> a(n);
        for(int &i:a)
            cin >> i;

        vector<vector<int>> dp(n, vector<int>((1<<(__lg(5000) + 1)), 1e9));

        dp[0][a[0]] = 0;
        for(int i = 0; i + 1 < n; i++){
            for(int j = 0; j < MAXX; j++){
                if(dp[i][j] == 1e9)
                    continue;
                if(j == 0){
                    dp[i + 1][a[i + 1]] = min(dp[i + 1][a[i + 1]], dp[i][0]);
                    dp[i + 1][0] = min(dp[i + 1][0], dp[i][0] + 1);
                }

                dp[i + 1][a[i + 1]] = min(dp[i + 1][a[i + 1]], dp[i][j] + 1);
                dp[i + 1][a[i + 1]^j] = min(dp[i + 1][a[i + 1]^j], dp[i][j] + 1);
            }
        }
        cout << dp[n - 1][0] << endl;
    }

    cerr << endl << "Running time: " << (double)clock()/CLOCKS_PER_SEC << " seconds."<< endl;

    return 0;
}