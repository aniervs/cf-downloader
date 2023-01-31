#include<bits/stdc++.h>
#define endl '\n' 
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;

using ll = long long;
using db = long double;
const int maxn = 2e5 + 5;
const ll mod = 1e9 + 7;

int cost(vector<int> ans){
    int res = 0;
    for(int i = 0; i + 1 < (int)ans.size(); i++){
        res = max(res, ans[i] ^ ans[i + 1]);
    }
    return res;
}



int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0); 

    int CASOS;
    cin >> CASOS;
    for(int caso = 1; caso <= CASOS; caso++){
        int n;
        cin >> n;
        int k = __lg(n - 1);
        int a = (1<<k);
        vector<int> ans;
        
        for(int i = (1<<k) + 1; i < n; i++)
            ans.push_back(i);
        ans.push_back(1<<k);
        ans.push_back(0);
        for(int i = 1; i < (1<<k); i++){
            if(i != a){
                ans.push_back(i);
            }
        }
        for(auto i:ans)
            cout << i << ' ';
        cout << endl;
    }

    cerr << endl << "Running time: " << (double)clock()/CLOCKS_PER_SEC << " seconds."<< endl;

    return 0;
}