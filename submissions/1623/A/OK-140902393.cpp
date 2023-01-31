#include <bits/stdc++.h>
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;

using ll = long long;
using db = long double;
const int maxn = 2e5 + 5;
const ll mod = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int CASOS;
    cin >> CASOS;
    for(int caso = 1; caso <= CASOS; caso++){
        int n, m, rb, cb, rd, cd;
        cin >> n >> m >> rb >> cb >> rd >> cd;
        rb--, cb--, rd--, cd--;
        vector<bool> row(n), col(m);
        int dr = 1, cr = 1;
        int ans = 0, curr = rb, curc = cb;

        row[rb] = col[cb] = 1;

        while(row[rd] == 0 and col[cd] == 0){
            if(curr + dr < 0 or curr + dr >= n)
                dr *= -1;
            if(curc + cr < 0 or curc + cr >= m)
                cr *= -1;
            curr += dr;
            curc += cr;
            ans++;
            row[curr] = 1;
            col[curc] = 1;
        }

        cout << ans << endl;   
    }
    return 0;
}