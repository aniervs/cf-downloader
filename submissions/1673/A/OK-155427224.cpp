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

int dp[maxn][2], sum[maxn];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0); 

    int CASOS;
    cin >> CASOS;
    for(int caso = 1; caso <= CASOS; caso++){
        string s;
        cin >> s;
        int n = (int)s.size();
        s = '$' + s;

        if(n == 1){
            cout << "Bob " << s[1] - 'a' + 1 << endl;
            continue;
        }

        dp[0][0] = dp[0][1] = 0;
        
        int max_sum[2] = {0, (int)-1e9};
        int min_sum[2] = {0, (int)1e9};

        for(int i = 1; i <= n; i++){
            sum[i] = sum[i-1] + s[i] - 'a' + 1;
            
            dp[i][0] = max_sum[i & 1] + sum[i];
            dp[i][1] = min_sum[!(i & 1)];

            max_sum[i & 1] = max(max_sum[i & 1], dp[i][1] - sum[i]);
            min_sum[i & 1] = min(min_sum[i & 1], dp[i][0]);
        }

        // cout << dp[1][0] << endl;
        // cout << dp[1][1] << endl;
        // return 0;

        int max_d = dp[n][0] - (sum[n] - dp[n][0]);

        for(int i = n - 1; i >= 1; i -= 2){
            if(i > 1)
            max_d = max(max_d, 2 * dp[i][0] - sum[n]);
        }

        if(max_d > 0) cout << "Alice " << max_d;
        else cout << "Bob " << -max_d;
        cout << endl;
    }

    cerr << endl << "Running time: " << (double)clock()/CLOCKS_PER_SEC << " seconds."<< endl;

    return 0;
}