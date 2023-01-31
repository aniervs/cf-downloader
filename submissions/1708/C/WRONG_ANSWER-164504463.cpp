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
        int iq = q;
        vector<int> a(n);
        for(auto &i:a)
            cin >> i;

        vector<bool> ans(n, 0);

        for(int i = 0; i < n; i++)
            if(a[i] <= q){
                ans[i] = 1;
            }
        
        vector<int> aux;
        for(int i = n - 1; i >= 0; i--){
            if(q == 0) break;
            if(a[i] > q){
                q--;
                aux.push_back(i);
            }
        }
        reverse(all(aux));

        for(auto i:aux){
            if(iq == 0)
                break;
            if(iq == 1 and i != n - 1)
                break;
            iq--;
            ans[i] = 1;

        }
        
        for(auto i:ans)
            cout << i;
        cout << endl;

    }
    

    cerr << endl << "Running time: " << (double)clock()/CLOCKS_PER_SEC << " seconds."<< endl;

    return 0;
}