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
        vector<int> v(n);
        for(auto &i:v)
            cin >> i;
        int h = 1;
        for(int i = 0; i < n; i++){
            if(i + 1 < n and !v[i] and !v[i+1]){
                h = -1;
                break;
            }
            if(v[i]){
                h += 1;
                if(i > 0 and v[i - 1]) h += 4;
            }
        }

        cout << h << endl;

    }
    
    return 0;
}