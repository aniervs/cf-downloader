#include<bits/stdc++.h>
#define endl '\n' 
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;

using ll = long long;
const int maxn = 4e4 + 5;
const ll mod = 1e9 + 7;

bool ispal(int x){
    string s = "";
    while(x){
        s += (x % 10) + '0';
        x /= 10;
    }
    string rs = s;
    reverse(all(rs));
    return rs == s;
}

ll dp[maxn][500];

ll add(ll x, ll y){ return (x + y >= mod) ? x + y - mod : x + y; }

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0); 

    vector<int> pals(1, 0);
    for(int i = 1; i < maxn; i++){
        if(ispal(i)){
            pals.push_back(i);
        }
    }

    

    dp[0][0] = 1;
    int k = pals.size();
    for(int i = 1; i < k; i++)
        for(int s = 0; s < maxn; s++){
            dp[s][i] = add(dp[s][i-1], dp[s][i]);
            if(pals[i] <= s) dp[s][i] = add(dp[s - pals[i]][i], dp[s][i]);
        }
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << dp[n][k - 1] << endl;
    }
    
    

    cerr << endl << "Running time: " << (double)clock()/CLOCKS_PER_SEC << " seconds."<< endl;

    return 0;
}