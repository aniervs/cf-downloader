#include<bits/stdc++.h>
#define endl '\n' 
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;

using ll = long long;
const int maxn = 2e5 + 5;

int dp[maxn][2][2];
int dps[maxn][2][2];

void upd(int i2, int j2, int k2, int i, int j, int k, int cost, int add){
    if(dp[i2][j2][k2] > dp[i][j][k] + cost){
        dp[i2][j2][k2] = dp[i][j][k] + cost;
        dps[i2][j2][k2] = dps[i][j][k] + add;
    } else if(dp[i2][j2][k2] == dp[i][j][k] + cost){
        dps[i2][j2][k2] = min(dps[i][j][k] + add, dps[i2][j2][k2]);
    }
}

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = '$' + s;

    for(int i = 0; i <= n; i++)
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 2; k++){
                dp[i][j][k] = 1e9;
                dps[i][j][k] = 1e9;
            }
        }
    
    dp[1][s[1] - '0'][1] = 0;
    dps[1][s[1] - '0'][1] = 1;
    dp[1][!(s[1] - '0')][1] = 1;
    dps[1][!(s[1] - '0')][1] = 1;

    for(int i = 1; i < n; i++){
        for(int j = 0; j < 2; j++){
            {
                // even length, try add a new segment
                upd(i + 1, !j, 1, i, j, 0, (int)(j == s[i + 1] - '0'), 1);

                // try to extend
                upd(i + 1, j, 1, i, j, 0, (int)(j != s[i + 1] - '0'), 0);
            }
            {
                // odd length, extend
                upd(i + 1, j, 0, i, j, 1, (int)(j != s[i + 1] - '0'), 0);
            }
        }
    }

    cout << min(dp[n][0][0], dp[n][1][0]) << ' ';

    if(dp[n][0][0] > dp[n][1][0]){
        cout << dps[n][1][0];
    } else if (dp[n][0][0] < dp[n][1][0]){
        cout << dps[n][0][0];
    } else{
        cout << min(dps[n][1][0], dps[n][0][0]);
    }

    cout << endl;
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