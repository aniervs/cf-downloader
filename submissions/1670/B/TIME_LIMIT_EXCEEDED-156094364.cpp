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
            char c; cin >> c; mark[c - 'a'] = 1;
        }

        set<int> all_pos, spec_pos;
        for(int i = 0; i < n; i++){
            all_pos.insert(i);
            if(mark[s[i] - 'a']) spec_pos.insert(i);
        }
        
        int ans = 0;

        while(true){
            vector<int> aux;
            for(int i:spec_pos){
                auto j = lower_bound(all(all_pos), i);
                if(j != all_pos.begin()){
                    aux.push_back(*prev(j));
                }
            }
            if(aux.empty())
                break;
            ans++;
            for(auto i: aux){
                if(spec_pos.find(i) != spec_pos.end()) spec_pos.erase(i);
                all_pos.erase(i);
            }
        }

        cout << ans << endl;



    }

    cerr << endl << "Running time: " << (double)clock()/CLOCKS_PER_SEC << " seconds."<< endl;

    return 0;
}