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
        int n, k;
        cin >> n >> k;
        vector<int> pos(n + 1);
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            pos[x] = i;
        }
        int ans = 1;
        while(ans < n and pos[ans] < pos[ans + 1]){
            ans++;
        }
        cout << (n - ans + k - 1) / k << '\n';
    }

    return 0;
}