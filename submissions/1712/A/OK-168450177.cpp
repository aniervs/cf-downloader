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
        int n, k;
        cin >> n >> k;
        vector<int> cnt(n + 1, 0);
        vector<int> a(n);
        for(int &i:a)
            cin >> i;
        auto b = a;
        for(int i = 0; i < k; i++)
            cnt[a[i]]++;
        sort(b.begin(), b.end());
        int ans = 0;
        for(int i = 0; i < k; i++) {
            if (!cnt[b[i]]) {
                ans++;
            } else {
                cnt[b[i]]--;
            }
        }

        cout << ans <<'\n';


    }

    return 0;
}