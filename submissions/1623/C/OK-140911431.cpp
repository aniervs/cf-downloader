#include <bits/stdc++.h>
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;

using ll = long long;
using db = long double;
const int maxn = 2e5 + 5;
const ll mod = 1e9 + 7;

bool isok(ll x, vector<ll> h){
    int n = h.size();
    auto a = h;
    for(int i = n - 1; i >= 2; i--){
        if(h[i] < x)
            continue;
        ll d = min((h[i] - x), a[i])/3ll * 3ll;
        h[i] -= d;
        h[i-1] += d / 3;
        d -= d/3ll;
        h[i-2] += d;
    }

    return *min_element(all(h)) >= x;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int CASOS;
    cin >> CASOS;
    for(int caso = 1; caso <= CASOS; caso++){
        int n;
        cin >> n;
        vector<ll> h(n);
        for(auto &i:h)
            cin >> i;
        ll l = 0, r = 1e9;
        while(l < r){
            ll mid = (l + r + 1)>>1;
            if(isok(mid, h))
                l = mid;
            else 
                r = mid - 1;
        }
        cout << l << endl;
    }
    return 0;
}