#include<bits/stdc++.h>
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;

using ll = long long;
using db = long double;
const int maxn = 2e5 + 5;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);

    int T;
    cin >> T;
    while(T--){
        int n, q;
        cin >> n >> q;
        vector<int> a(n);

        for(int &i:a)
            cin >> i;

        int c = 0;

        vector<vector<int>> rounds(n);

        for(int i = 0; i < n and a[i] != n; i++) {
            int j = i;
            while (j + 1 < n and a[j + 1] < a[i])
                j++;
            if (i != 0) {
                rounds[i].push_back(++c);
            }
            for (int k = i + 1; k <= j; k++) {
                rounds[i].push_back(++c);
            }
            i = j;
        }

        while(q--){
            int p, k;
            cin >> p >> k;
            p--;
            int ans = upper_bound(all(rounds[p]), k) - rounds[p].begin();

            if(a[p] == n){
                ans += k - p;
                if(p != 0) ans++;
            }

            cout << ans << endl;
        }

    }
    cerr << endl << "Running time: " << (double)clock()/CLOCKS_PER_SEC << " seconds."<< endl;

    return 0;
}