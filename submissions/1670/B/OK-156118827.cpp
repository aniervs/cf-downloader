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

    int CASOS;
    cin >> CASOS;
    for(int caso = 1; caso <= CASOS; caso++){
        int n, k;
        string s;

        cin >> n >> s >> k;
        vector<bool> mark(26, 0);
        while(k--){
            char c;
            cin >> c;
            mark[c - 'a'] = 1;
        }
        int ans = 0;
        int last_mark = -1;
        for(int i = 1; i <= n; i++){
            if(mark[s[i-1] - 'a']){
                if(last_mark != -1)
                    ans = max(ans, i - last_mark);
                else 
                    ans = max(ans, i - 1);
                last_mark = i;
            }
        }

        cout << ans << endl;



    }

    cerr << endl << "Running time: " << (double)clock()/CLOCKS_PER_SEC << " seconds."<< endl;

    return 0;
}