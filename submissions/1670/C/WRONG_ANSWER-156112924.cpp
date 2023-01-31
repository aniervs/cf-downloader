#include<bits/stdc++.h>
#define endl '\n' 
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;

using ll = long long;
using db = long double;
const int maxn = 2e5 + 5;
const ll mod = 1e9 + 7;

int a[2][maxn], pos[2][maxn], color[maxn], nxt[maxn], who[maxn];
bool vis[maxn];

vector<int> G[maxn];
bool is_bip;
int sz;

void dfs(int u){
    vis[u] = 1;
    sz++;
    for(int v:G[u]){
        if(!vis[v]){
            vis[v] = 1;
            if(color[v] == -1){
                color[v] = !color[u];
                dfs(v);
            } else{
                if(color[v] == color[u]){
                    is_bip = false;
                }
            }
        }
    }
}

void add_edge(int u, int v){
    // cerr << u << ' ' << v << endl;
    G[u].push_back(v);
    G[v].push_back(u);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0); 

    int CASOS;
    cin >> CASOS;
    for(int caso = 1; caso <= CASOS; caso++){
        int n;
        cin >> n;
        for(int j = 0; j < 2; j++)
        for(int i = 1; i <= n; i++){
            cin >> a[j][i];
            pos[j][a[j][i]] = i;
        }
        for(int i = 1; i <= 2*n; i++){
            G[i].clear();
            color[i] = -1;
            who[i] = i;
            vis[i] = false;
        }

        for(int i = 1; i <= n; i++){
            int d; cin >> d;
            if(d == 0) continue;
            if(d == a[0][i]) color[i] = 1;
            else color[n + i] = 1;
        }

        

        for(int i = 1; i <= n; i++){
            if(a[0][i] != a[1][i]){
                add_edge(i, pos[1][a[0][i]]  + n);
                add_edge(i + n, pos[0][a[1][i]]);
            }
            add_edge(i, i + n);
        }

        int cc = 0;
        is_bip = true;

        for(int i = 1; i <= 2*n and is_bip; i++){
            if(i <= n and a[0][i] == a[1][i]) continue; 
            if(i > n and a[0][i-n] == a[1][i-n]) continue;
            if(color[i] != -1 and !vis[i]){
                dfs(i);
            }
        }

        for(int i = 1; i <= 2*n and is_bip; i++){
            if(i <= n and a[0][i] == a[1][i]) continue; 
            if(i > n and a[0][i-n] == a[1][i-n]) continue;
            if(color[i] == -1){
                sz = 0;
                color[i] = 1;
                dfs(i);
                if(sz > 1)
                    cc++;
            }
        }
        
        if(!is_bip){
            cout << 0 << endl;
            continue;
        }

        
        ll ans = 1;
        while(cc--){
            ans = ans * 2 % mod; 
        }
        cout << ans << endl;
    }

    cerr << endl << "Running time: " << (double)clock()/CLOCKS_PER_SEC << " seconds."<< endl;

    return 0;
}