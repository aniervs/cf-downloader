/**
  Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools

  To modify the template, go to Preferences -> Editor -> File and Code Templates -> Other
*/

#include <bits/stdc++.h>

using namespace std;

bool isOk(int k, int x, vector<int> a){
    for(int &i:a)
        if(i * 2 < x){
            k--;
            i = 1e9;
        }
    if(k < 0)
        return false;
    cerr << "Alive!" << endl;
    cerr << "k = " << k << endl;
    int n = (int)a.size();
    if(k == 0){
        int diam = 0;
        for(int i = 1; i < n; i++){
            diam = max(diam, min(a[i], a[i - 1]));
        }
        diam = min(diam, 2 * (*min_element(a.begin(), a.end())));

        return (diam >= x);
    }
    if(k == 1){
        return (*max_element(a.begin(), a.end()) >= x);
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int &i: a)
            cin >> i;
        int l = 1, r = 1e9;
        while(l < r){
            int mid = (l + r + 1)>>1;
            if(isOk(k, mid, a))
                l = mid;
            else
                r = mid - 1;
        }
        cout << l << '\n';
    }

    return 0;
}