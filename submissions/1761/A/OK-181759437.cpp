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
        int n, a, b;
        cin >> n >> a >> b;
        if(n == a and b == n){
            cout << "Yes\n";
            continue;
        }
        if(a + b >= n - 1){
            cout << "No";
        } else{
            cout << "Yes";
        }
        cout << '\n';
    }

    return 0;
}