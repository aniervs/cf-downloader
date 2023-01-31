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

        int n, q;
        cin >> n >> q;
        vector<int> a(n), min_suf(n);
        for(auto &i:a)
            cin >> i;

        vector<bool> ans(n, 0);

        int max_horizontal = -1;
        for(int i = 0; i < n; i++)
            if(a[i] <= q){
                ans[i] = 1;
                max_horizontal = i;
            }
                

        for(int i = 0; i < n; i++){
            if(q == 0) break;
            if(a[i] > q){
                if(q == 1 and max_horizontal > i) break;
                q--;
                ans[i] = 1;
            }
        }
        for(auto i:ans)
            cout << i;
        cout << endl;

    }
    

    cerr << endl << "Running time: " << (double)clock()/CLOCKS_PER_SEC << " seconds."<< endl;

    return 0;
}