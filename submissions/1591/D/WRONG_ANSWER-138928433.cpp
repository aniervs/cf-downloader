#include<bits/stdc++.h>
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define lg2(x) __lg(x)
using namespace std;

typedef long long ll;

const int maxn = (int)1e5 + 5;
int abi[maxn], n;

void upd(int p){ for(; p > 0; p -= p & -p) abi[p]++; }
int sum(int p){ int res = 0; for(; p <= n; p += p & -p ) res += abi[p]; return res; }

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);

    int CASOS;
    cin >> CASOS;
    for(int caso = 1; caso <= CASOS; caso++){
        cin >> n;
        vector<int> a(n);
        for(int &i:a)
            cin >> i;
        
        if(n == 1){
            cout << "YES" << endl;
            continue;
        }
        if(n == 2){
            cout << (a[0] <= a[1] ? "YES" : "NO") << endl;
            continue;
        }

        auto aux = a;
        sort(all(aux));
        aux.erase(unique(all(aux)), aux.end());

        fill(abi, abi + n + 1, 0);

        ll ninv = 0;
        for(int i:a){
            i = upper_bound(all(aux), i) - aux.begin();
            ninv += sum(i + 1);
            upd(i);
        }

        if(ninv % 2 == 0){
            cout << "YES";
        } else{
            cout << "NO";
        }
        cout << endl;
    }
    
    return 0;
}