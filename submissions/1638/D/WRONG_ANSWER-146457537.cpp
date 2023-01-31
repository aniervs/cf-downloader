#include<bits/stdc++.h>
#define endl '\n' 
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;

using ll = long long;
using db = long double;
const int maxn = 1e3 + 5;
const ll mod = 1e9 + 7;


int n, m, a[maxn][maxn], b[maxn][maxn], c[maxn][maxn];
const int mr[] = {0, 0, 1, 1};
const int mc[] = {0, 1, 0, 1};

const int mr2[] = {1, 1, -1, -1, 0, 0, -1, 1};
const int mc2[] = {1, -1, 1, -1, 1, -1, 0, 0};

int check(int i, int j){
    vector<int> colors;
    for(int k = 0; k < 4; k++){
        if(i + mr[k] > n or i + mr[k] < 1 or j + mc[k] > n or j + mc[k] < 1)
            return -1;
        if(a[i + mr[k]][j + mc[k]] != -1)
            colors.push_back(a[i + mr[k]][j + mc[k]]);
    }
    sort(all(colors));
    colors.erase(unique(all(colors)), colors.end());
    // cerr << i << ' ' << j << ": "; for (auto i:colors) cerr << i << ' '; cerr << endl;
    if(colors.size() == 1) return colors[0];
    return -1;
}

bool aux[maxn][maxn];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0); 

    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
            c[i][j] = a[i][j];
        }
    }

    vector<array<int,3>> sol;

    queue<array<int, 2>> Q;
    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            if(check(i, j) != -1){
                Q.push({i, j});
            }
        }
    }

    while(!Q.empty()){
        int r = Q.front()[0];
        int c = Q.front()[1];
        Q.pop();
        
        if(aux[r][c]) continue;
        int x = check(r, c);

        if(x == -1) continue;

        aux[r][c] = 1;
        sol.push_back({r, c, x});

        for(int i = 0; i < 4; i++){
            int nr = r + mr[i];
            int nc = c + mc[i];
            a[nr][nc] = -1;
        }

        for(int i = 0; i < 8; i++){
            int nr = r + mr2[i];
            int nc = c + mc2[i];
            if(check(nr, nc) != -1 and !aux[nr][nc]){
                Q.push({nr, nc});
            }
        }
    }

    reverse(all(sol));
    for(auto [i, j, c]:sol){
        b[i][j] = b[i + 1][j] = b[i][j + 1] = b[i + 1][j + 1] = c;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(c[i][j] != b[i][j]){
                cout << -1;
                return 0;
            }
        }

    }

    sort(all(sol));
    for(int i = 0; i + 1 < (int)sol.size(); i++){
        assert(sol[i][0] != sol[i+1][0] or sol[i][1] != sol[i+1][1]);
    }
    
    cout << sol.size() << endl;
    
    for(auto [i, j, c]:sol){
        cout << i << ' ' << j << ' ' << c << endl;
    }
    
    cerr << endl << "Running time: " << (double)clock()/CLOCKS_PER_SEC << " seconds."<< endl;

    return 0;
}
