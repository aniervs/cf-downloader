#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)x.size()
using ll = long long;
const int maxn = 2e5 + 5;

int p[maxn], nxt[maxn], mark[maxn];
int sum_length_cycles;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        int ans = INT_MAX;
        for(int i = 1; i <= n; i++){
            cin >> p[i];
            nxt[i] = p[i];
            mark[i] = 0;
        }
        sum_length_cycles = 0;
        for(int i = 1; i <= n; i++){
            if(mark[i]) continue;
            int j = i;
            sum_length_cycles--;
            while(!mark[j]){
                mark[j] = i;
                sum_length_cycles++;
                j = nxt[j];
            }
        }

        for(int i = 1; i < n; i++){
            int old_sum_length_cycles = sum_length_cycles;

            int cnt = 0;
            if(mark[i] == mark[i + 1]){
                ans = min(ans, sum_length_cycles - 1);
            } else {
                cnt++;
                sum_length_cycles++;
                ans = min(ans, cnt + sum_length_cycles - 1);
                sum_length_cycles = old_sum_length_cycles;
            }
        }


        cout << ans << '\n';
    }

    return 0;
}