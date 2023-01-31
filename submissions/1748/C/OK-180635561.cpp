#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const ll mod = 1e9 + 7;
const int maxn = (int)2e5 + 5;

#define all(x) (x).begin(), (x).end()

void solve(){

    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &i:a)
        cin >> i;
    
    int ans = 0;
    int cnt = count(all(a), 0);
    for(int cc = 0; cc < cnt; cc++){
        vector<ll> tmp;
        while(a.back() != 0){
            tmp.push_back(a.back());
            a.pop_back();
        }
        tmp.push_back(0);
        a.pop_back();

        reverse(all(tmp));
        ll m = (ll)tmp.size();
        for(int i = 1; i < m; i++)
            tmp[i] += tmp[i - 1];
        sort(all(tmp));

        int mxcnt = 0;
        for(int i = 0; i < m; i++){
            int j = i;
            while(j + 1 < m and tmp[j + 1] == tmp[j])
                j++;
            mxcnt = max(mxcnt, j - i + 1);
            i = j;
        }
        ans += mxcnt;
    }
    ll s = 0;
    for(int i = 0; i < (int)a.size(); i++){
        s += a[i];
        if(s == 0)
            ans++;
    }
    cout << ans << '\n';

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll T;
    cin >> T;
    while(T--){
        solve();
        
    }
    

    return 0;
}