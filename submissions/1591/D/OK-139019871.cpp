#include<bits/stdc++.h>
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define lg2(x) __lg(x)
using namespace std;

typedef long long ll;

const int maxn = (int)1e5 + 5;
int abi[maxn], n;

void upd(int p){ for(; p > 0; p -= p & -p) abi[p]++; }
int sum(int p){ int res = 0; for(; p <= n; p += p & -p ) res += abi[p]; return res; }

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);

    int CASOS;
    cin >> CASOS;
    for(int caso = 1; caso <= CASOS; caso++){
        cin >> n;
        vector<int> a(n), cnt(n, 0);

        for(int &i:a){
            cin >> i;
            cnt[--i]++;
        }

        
        if(n == 1){
            cout << "YES" << endl;
            continue;
        }
        if(n == 2){
            cout << (a[0] <= a[1] ? "YES" : "NO") << endl;
            continue;
        }
        if(*max_element(all(cnt)) > 1){
            cout << "YES" << endl;
            continue;
        }

        vector<int> pos(n);
        for(int i = 0; i < n; i++)
            pos[a[i]] = i;
        
        for(int i = 0; i < n - 2; i++){
            if(a[i] == i)
                continue;
            
            int j = pos[i];
            if(j == n - 1){
                swap(a[i], a[j]);
                swap(a[i + 1], a[j]); 
                pos[a[i]] = i, pos[a[i + 1]] = i + 1, pos[a[j]] = j;
            } else{
                swap(a[i], a[j]);
                swap(a[j], a[n - 1]);
                pos[a[i]] = i, pos[a[j]] = j, pos[a[n - 1]] = n - 1;
            }
        }

        if(a[n - 1] == n - 1){
            cout << "YES";
        } else{
            cout << "NO";
        }
        cout << endl;
    }
    
    return 0;
}