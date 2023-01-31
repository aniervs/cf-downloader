/**
  Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools

  To modify the template, go to Preferences -> Editor -> File and Code Templates -> Other
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vector<int> a(n), max_pos(n + 1, -1);
        vector<bool> is_sorted(n + 1, 0);
        for(int i = 0; i < n; i++){
            cin >> a[i];
            max_pos[a[i]] = i;
        }
        is_sorted[n] = 1;
        for(int i = n - 1; i >= 0; i--){
            is_sorted[i] = is_sorted[i + 1];
            if(i + 1 < n and a[i] > a[i + 1]){
                is_sorted[i] = false;
                break;
            }
        }

        set<int> s;
        int ans = 1e9, mxpos = -1;
        for(int i = 0; i <= n; i++){
            if(is_sorted[i] and mxpos < i){
                ans = min(ans, (int)s.size());
            }
            if(i < n){
                s.insert(a[i]);
                mxpos = max(mxpos, max_pos[a[i]]);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}