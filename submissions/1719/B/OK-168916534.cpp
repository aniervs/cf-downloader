#include<bits/stdc++.h>
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;

using ll = long long;
using db = long double;
const int maxn = 2e5 + 5;
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);



    int T;
    cin >> T;
    while(T--) {
        int n, k;
        cin >> n >> k;
        k %= 4;

        if (k == 0) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        if (k == 1) {
            for (int i = 1; i <= n; i += 2) {
                cout << i << ' ' << i + 1 << ' ';
            }
        }
        if (k == 3) {
            for (int a = 3; a <= n; a += 4) {
                cout << a << ' ' << a - 1 << endl;
            }
            for (int b = 4; b <= n; b += 4) {
                cout << b - 3 << ' ' << b << endl;
            }
            if (n % 4) {
                cout << n - 1 << ' ' << n << endl;
            }
        }
        if (k == 2) {
            for(int a = 2; a <= n; a += 4){
                cout << a << ' ' <<  a - 1 << endl;
            }
            for(int b = 4; b <= n; b += 4){
                cout << b - 1 << ' ' << b << endl;
            }
        }

        cout << endl;
    }

    cerr << endl << "Running time: " << (double)clock()/CLOCKS_PER_SEC << " seconds."<< endl;

    return 0;
}