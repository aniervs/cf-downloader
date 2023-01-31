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
        string s;
        cin >> s;
        int mask = 0;
        for(char c:s)
            mask |= (1<<(c - 'a'));

        if(__builtin_popcount(mask) == 1){
            cout << "YES" << endl;
            continue;
        }

        int min_diff = 1e9;
        int max_diff = -1e9;
        
        for(char u = 'a'; u <= 'z'; u++){
            if(!(mask & (1<<(u -'a')))) continue;
            for(char v = u + 1; v <= 'z'; v++){
                if(!(mask & (1<<(v -'a')))) continue;

                int min_sum = 0;
                int max_sum = 0;
                int sum = 0;


                for(char c:s){
                    if(c!=u and c != v) continue;
                    if(c == u) sum++;
                    else sum--;

                    max_diff = max(sum - min_sum, max_diff);
                    max_diff = max(sum - max_sum, max_diff);

                    min_diff = min(sum - min_sum, min_diff);
                    min_diff = min(sum - max_sum, min_diff);

                    min_sum = min(min_sum, sum);
                    max_sum = max(max_sum, sum);
                }
            }
        }

        min_diff = abs(min_diff);

        if(max(min_diff, max_diff) > 1){
            cout << "NO";
        } else{
            cout << "YES";
        }
        cout << endl;
        
    }

    cerr << endl << "Running time: " << (double)clock()/CLOCKS_PER_SEC << " seconds."<< endl;

    return 0;
}