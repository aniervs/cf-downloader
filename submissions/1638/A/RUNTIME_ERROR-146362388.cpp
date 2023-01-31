#include<bits/stdc++.h>
#define endl '\n' 
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;

using ll = long long;
using db = long double;
const int maxn = 2e5 + 5;
const ll mod = 1e9 + 7;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0); 

    int CASOS;
    cin >> CASOS;
    for(int caso = 1; caso <= CASOS; caso++){
        int n;
        cin >> n;
        vector<int> a(n), pos(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
            pos[a[i]] = i;
        }
        for(int i = 0; i < n; i++){
            if(i != pos[i + 1]){
                reverse(a.begin() + i,a .begin() + pos[i + 1] + 1);
                break;
            }
        }

        for(int i:a){
            cout << i << ' ';
        }
        cout << endl;
    }

    cerr << endl << "Running time: " << (double)clock()/CLOCKS_PER_SEC << " seconds."<< endl;

    return 0;
}