#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const ll mod = 1e9 + 7;
const int maxn = (int)2e5 + 5;

#define all(x) (x).begin(), (x).end()

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ans = 0;
        for(int i = 0; i < n; i++){
            int cnt_one = 0;
            int mx = 0;
            vector<int> cnt(10);
            for(int j = i; j < n and j < i + 100; j++){
                int a = s[j] - '0';
                cnt[a]++;
                if(cnt[a] == 1) cnt_one++;
                mx = max(mx, cnt[a]);
                if(mx <= cnt_one){
                    ans++;
                }
            }
        }
        cout << ans <<'\n';
    }
    

    return 0;
}