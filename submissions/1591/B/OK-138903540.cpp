#include<bits/stdc++.h>
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define lg2(x) __lg(x)
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);

    int CASOS;
    cin >> CASOS;
    for(int caso = 1; caso <= CASOS; caso++){
        int n;
        cin >> n;

        int mx = -1;
        int ans = 0;

        vector<int> a(n);
        for(int &i:a)
            cin >> i;
        while(!a.empty()){
            while(!a.empty() and a.back() <= mx)
                a.pop_back();
            if(!a.empty()){
                mx = max(mx, a.back());
                ans++;
            }
        }


        cout << ans - 1 << endl;

    }
    
    return 0;
}