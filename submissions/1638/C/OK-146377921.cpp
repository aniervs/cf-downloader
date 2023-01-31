#include<bits/stdc++.h>
#define endl '\n' 
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;

using ll = long long;
using db = long double;
const int maxn = 2e5 + 5;

int par[maxn], nCC, a[maxn];

int rootfind(int u){
    if(u == par[u]) return u;
    return par[u] = rootfind(par[u]);
}

void join(int u, int v){
    u = rootfind(u), v = rootfind(v);
    if(u == v) return;
    if(u < v) swap(u, v);
    par[v] = u;
    nCC--;
}

void solve(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        par[i] = i;
        cin >> a[i];
    }
    nCC = n;

    priority_queue<int> ccs;


    for(int i = 1; i <= n; i++){
        int aux = a[i];
        while(!ccs.empty() and ccs.top() > aux){
            int u = ccs.top();
            ccs.pop();
            a[i] = max(a[i], u);
            join(u, a[i]);
        }
        ccs.push(a[i]);
    }

    cout << ccs.size() << endl;
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