#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const ll mod = 1e9 + 7;
const int maxn = (int)2e5 + 5;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int cnt = 0;
        bool flag = false;
        for(int i = n - 1; i >= 0; i--){
            if(s[i] == 'A'){
                cnt++;
            } else{
                if(cnt < 1){
                    flag = true;
                } else{
                    cnt--;
                }
            }
        }
        if(flag) cout << "No";
        else cout << "Yes";
        cout << '\n';
    }
    

    return 0;
}