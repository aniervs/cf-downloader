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

bool isok(vector<int> a, int t, int q){
    int n = (int)a.size();

    for(int i = t; i < n; i++){
        if(q == 0)
            return 0;
        if(a[i] > q)
            q--;
    }
    return 1;

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0); 

    int CASOS = 1;
    cin >> CASOS;
    for(int caso = 1; caso <= CASOS; caso++){

        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        for(auto &i:a)
            cin >> i;

        int l = 0, r = n - 1;
        while(l < r){
            int mid = (l + r) >> 1;
            if(isok(a, mid, q))
                r = mid;
            else 
                l = mid + 1;
        }
        
        vector<bool> ans(n);
        for(int i = 0; i < l; i++){
            if(a[i] <= q){
                ans[i] = 1;
            }
        }
        for(int i = l; i < n; i++){
            ans[i] = 1;
            if(a[i] > q)
                q--;
        }

        for(int i = 0; i < n; i++)
            cout << ans[i];
        
        cout << endl;

    }
    

    cerr << endl << "Running time: " << (double)clock()/CLOCKS_PER_SEC << " seconds."<< endl;

    return 0;
}