#include<bits/stdc++.h>
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define lg2(x) __lg(x)
using namespace std;

typedef long long ll;

int k;

ll solve(vector<int> a){ 
    if(a.empty()) return 0;
    sort(rall(a));
    ll ans = 0;
    int n = a.size();
    for(int i = 0; i < n; i += k){
        ans += a[i]*2ll;
    }

    return ans;
}


ll solve_no_back(vector<int> a){
    if(a.empty()) return 0;
    sort(rall(a));
    ll ans = a[0];
    int n = a.size();
    for(int i = k; i < n; i += k){
        ans += a[i]*2ll;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);

    int CASOS;
    cin >> CASOS;
    for(int caso = 1; caso <= CASOS; caso++){
        int n;
        cin >> n >> k;
        vector<int> a(n);
        vector<int> pos, neg;

        for(int &i:a){
            cin >> i;   
            if(i == 0)
                continue;
            if(i > 0)
                pos.push_back(i);
            else
                neg.push_back(-i);
        }

        ll ans = min(solve(pos) + solve_no_back(neg), solve(neg) + solve_no_back(pos));
        cout << ans << endl;


        

    }
    
    return 0;
}