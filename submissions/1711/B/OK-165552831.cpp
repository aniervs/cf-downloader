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

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0); 

    int CASOS = 1;
    cin >> CASOS;
    for(int caso = 1; caso <= CASOS; caso++){
        int n, m;
        cin >> n >> m;
        vector<int> a(n), deg(n, 0);
        for(int &i:a)
            cin >> i;
        vector<pair<int,int>> edges(m);
        for(auto &[x, y]:edges){
            cin >> x >> y;
            x--, y--;
            deg[x]++, deg[y]++;
        }

        if(m % 2 == 0){
            cout << 0 << endl;
        } else{
            int ans = 1e9;
            for(int i = 0; i < n; i++)
                if(deg[i]&1)
                    ans = min(ans, a[i]);
            for(auto [x, y]:edges){
                if((deg[x] + deg[y] - 1) % 2){
                    ans = min(ans, a[x] + a[y]);
                }
            }
            cout << ans << endl;
        }
    }
    

    cerr << endl << "Running time: " << (double)clock()/CLOCKS_PER_SEC << " seconds."<< endl;

    return 0;
}