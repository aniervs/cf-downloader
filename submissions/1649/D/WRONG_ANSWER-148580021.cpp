#include<bits/stdc++.h>
#define endl '\n' 
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;

using ll = long long;
using db = long double;
const int maxn = 1e6 + 5;


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0); 

    int CASOS;
    cin >> CASOS;
    for(int caso = 1; caso <= CASOS; caso++){
        int n, c;
        cin >> n >> c;
        vector<int> arr(n);
        vector<bool> mark(c + 1);
        for(auto &i:arr){
            cin >> i;
            mark[i] = 1;
        }
        sort(all(arr));
        
        
        bool ans = true;

        for(int i = 0; i < n; i++){
            int y = arr[i];
            int r = i - 1;
            for(int z = y; z <= arr[n-1]; z+=y){
                int a = z / y;
                    
                if(!mark[a]) continue;
                
                if(r + 1 < n and (arr[r + 1] < z or arr[r + 1] >= z + y)){
                    ans = false;
                    break;
                }
                while(r + 1 < n and arr[r + 1] >= z and arr[r + 1] < z + y) r += 1;
            }

            if(r != n - 1) ans = false;
            
        
            if(!ans) break;
        }

        if(ans) cout << "Yes";
        else cout << "No";

        cout << endl;
    }

    cerr << endl << "Running time: " << (double)clock()/CLOCKS_PER_SEC << " seconds."<< endl;

    return 0;
}