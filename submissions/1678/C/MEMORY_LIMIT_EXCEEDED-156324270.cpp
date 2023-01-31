#include<bits/stdc++.h>
#define endl '\n' 
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;

using ll = long long;

const int maxn = 5005;

int p[maxn], cnt[maxn][maxn];

ll get_sum(int lx, int rx, int ly, int ry){
    if(rx < lx) return 0;
    if(ry < ly) return 0;


    return cnt[ly][ry] - cnt[lx - 1][ry] - cnt[ly][rx - 1] + cnt[lx - 1][rx - 1];
}

void solve(){

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> p[i];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            cnt[i][j] = 0;
        }
    }

    vector<pair<int,int>> AC;

    for(int a = 1; a <= n; a++){
        for(int c = a + 2; c <= n; c++){
            if(p[a] < p[c]){
                AC.push_back({a, c});
            }
        }
    }

    for(int b = 1; b <= n; b++){
        for(int d = b + 2; d <= n; d++){
            if(p[b] > p[d]){
                cnt[b][d]++;
            }
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cnt[i][j] += cnt[i-1][j] + cnt[i][j-1] - cnt[i-1][j-1];
        }
    }

    ll ans = 0;

    for(auto [a, c]:AC){
        ans += get_sum(a + 1, c + 1, c - 1, n);
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