#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const ll mod = 1e9 + 7;
const int maxn = (int)2e5 + 5;

#define all(x) (x).begin(), (x).end()

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int T;
    cin >> T;
    while(T--){
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> a(k);
        for(int &i:a)
            cin >> i;
        reverse(all(a));

        vector<bool> mark(n + 1, 0);
        int cnt_board = 0;
        bool flag = false;
        for(int i = k; i >= 1; i--){
            if(mark[i]){
                cnt_board--;
                continue;
            }
            while(a.back() != i){
                mark[a.back()] = 1;
                cnt_board++;
                a.pop_back();
            }
            if(n + m - 3 > n * m - 2 - cnt_board){
                flag = true;
                break;
            }
            a.pop_back();
            mark[i] = 1;
        }

        if(flag) cout << "TIDAK";
        else cout << "YA";

        cout << '\n';
    }
    

    return 0;
}