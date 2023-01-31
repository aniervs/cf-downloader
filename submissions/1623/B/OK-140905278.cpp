#include <bits/stdc++.h>
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;

using ll = long long;
using db = long double;
const int maxn = 2e5 + 5;
const ll mod = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int CASOS;
    cin >> CASOS;
    for(int caso = 1; caso <= CASOS; caso++){
        int n;
        cin >> n;
        vector<vector<bool>> mark(n, vector<bool>(n, 0));
        vector<pair<int,int>> a(n);
        for(auto &[l, r]:a){
            cin >> l >> r;
            l--, r--;
            mark[l][r] = 1;
        }
        for(auto [l, r]:a){
            for(int d = l; d <= r; d++){
                if(d > l and !mark[l][d - 1])
                    continue;
                if(d < r and !mark[d + 1][r])
                    continue;
                cout << l + 1 << ' ' << r + 1 << ' ' << d + 1 << endl;
                break;
            }
        }
    }
    return 0;
}