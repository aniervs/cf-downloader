#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int maxn = 2e5 + 5;
#define all(x) (x).begin(), (x).end()

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(9);
    
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(auto &i:a)
            cin >> i;
        int ans = 0;

        while(!a.empty()){
            vector<int> cnt(n + 1, 0);
            for(auto i:a)
                cnt[i]++;
            if(*max_element(all(cnt)) < 2){
                ans += (int)a.size();
                break;
            }
            int f = -1, g = -1;
            for(int i = 0; i < (int)a.size(); i++){
                if(cnt[a[i]] > 1){
                    int l = (i - 1 + (int)a.size())%(int)a.size();
                    int r = (i + 1)%(int)a.size();
                    if(a[l] != a[r]){
                        f = i;  
                        break;
                    }
                    g = i;
                }
            }
            

            ans++;
            if(f != -1){
                a.erase(a.begin() + f);
            } else{
                a.erase(a.begin() + g);
            }

            if((int)a.size() > 1){
                for(int i = 0; i < (int)a.size(); i++){
                    int j = (i + 1)%(int)a.size();
                    if(a[i] == a[j]){
                        a.erase(a.begin() + i);
                        break;
                    }
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}