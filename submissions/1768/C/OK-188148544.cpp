#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)x.size()
using ll = long long;
const int maxn = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vector<int> a(n);
        vector<vector<int>> pos(n + 1);
        for(int i = 0; i < n; i++){
            cin >> a[i];
            pos[a[i]].push_back(i);
        }

        bool ans = true;
        vector<int> p(n, -1), q(n, -1);
        vector<int> half_free_p, half_free_q;
        for(int i = n; i >= 1; i--){
            if(pos[i].size() > 2){
                ans = false;
                break;
            }
            if(pos[i].size() == 1){
                p[pos[i][0]] = q[pos[i][0]] = i;
                continue;
            }
            if(pos[i].size() == 2){
                int p1 = pos[i][0];
                int p2 = pos[i][1];
                if(p[p1] == -1 and q[p2] == -1){
                    p[p1] = q[p2] = i;
                    if(q[p1] == -1) half_free_q.push_back(p1);
                    if(p[p2] == -1) half_free_p.push_back(p2);
                } else if(p[p2] == -1 and q[p1] == -1){
                    p[p2] = q[p1] = i;
                    if(q[p2] == -1) half_free_q.push_back(p2);
                    if(p[p1] == -1) half_free_p.push_back(p1);
                } else{
                    ans = false;
                    break;
                }
                continue;
            }

            if(pos[i].empty()){
                if(half_free_p.empty() or half_free_q.empty()){
                    ans = false;
                    break;
                }
                int pp = half_free_p.back();
                int qq = half_free_q.back();
                p[pp] = q[qq] = i;
                half_free_p.pop_back();
                half_free_q.pop_back();
            }


        }

        if(!ans){
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        for(auto i:p) cout << i << ' ';
        cout << '\n';
        for(auto i:q) cout << i << ' ';
        cout << '\n';



    }


    return 0;
}