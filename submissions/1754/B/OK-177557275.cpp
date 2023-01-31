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
        int n;
        cin >> n;
        vector<int> ans;
        if(n % 2 == 1)
            ans.push_back(1);
        int x = (n + 1)/2;
        int y = n;
            
        for(int i = 0; i < n/2; i++){
            ans.push_back(x--);
            ans.push_back(y--);
        }
        
        for(auto i:ans)
            cout << i << ' ';
        cout << '\n';
    }
    
    

    return 0;
}