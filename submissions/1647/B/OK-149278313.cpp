#include<bits/stdc++.h>
#define endl '\n' 
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;

using ll = long long;
using db = long double;
const int maxn = 2e5 + 5;
const ll mod = 1e9 + 7;

const int mr[] = {0, 0, 1, -1};
const int mc[] = {1, -1, 0, 0};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0); 

    int CASOS;
    cin >> CASOS;
    for(int caso = 1; caso <= CASOS; caso++){
        int n, m;
        cin >> n >> m;
        vector<string> a(n);
        for(auto &s:a)
            cin >> s;
        bool good = true;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(a[i][j] == '1'){
                    if(i > 0 and j > 0 and a[i-1][j] == '1' and a[i][j-1] == '1' and a[i-1][j-1] != '1'){
                        good = false;
                        break;
                    }
                    if(i > 0 and j + 1 < m and a[i-1][j] == '1' and a[i][j + 1] == '1' and a[i-1][j + 1] != '1'){
                        good = false;
                        break;
                    }
                    if(i + 1 < n and j + 1 < m and a[i][j+1] == '1' and a[i+1][j] == '1' and a[i+1][j+1] != '1'){
                        good = false;
                        break;
                    }
                    if(i + 1 < n and j > 0 and a[i][j-1] == '1' and a[i+1][j] == '1' and a[i+1][j-1] != '1'){
                        good = false;
                        break;
                    }
                }
            }
        }
        if(good) cout << "YES";
        else cout << "NO";
        cout << endl;
        
    }

    cerr << endl << "Running time: " << (double)clock()/CLOCKS_PER_SEC << " seconds."<< endl;

    return 0;
}