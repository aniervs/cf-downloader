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
        if(n & 1){
            cout << 1 << ' ';
            for(int i = 3; i <= n; i+=2){
                cout << i << ' ' << i - 1 << ' ';
            }
        } else{
            for(int i = 2; i <= n; i+=2){
                cout << i << ' ' << i - 1 << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}