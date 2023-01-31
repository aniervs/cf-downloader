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
        vector<int> a(n);
        vector<int> cnt(105, 0);
        int zeroes = 0;
        for(auto &i:a){
            cin >> i;
            if(i == 0) zeroes++;
            else cnt[i]++;
        }
        if(zeroes > 0 or *max_element(all(cnt)) > 1) cout << n - zeroes << endl;
        else cout << n - zeroes + 1 << endl;
        

    }

    cerr << endl << "Running time: " << (double)clock()/CLOCKS_PER_SEC << " seconds."<< endl;

    return 0;
}