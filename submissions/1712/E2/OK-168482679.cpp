/**
  Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools

  To modify the template, go to Preferences -> Editor -> File and Code Templates -> Other
*/

#include <bits/stdc++.h>

using namespace std;

const int maxn = 4e5 + 5;

long long choose2(long long n){ return n * (n - 1) >> 1; }
long long choose3(long long n){ return n * (n - 1) * (n - 2) / 6; }

vector<int> divisors[maxn];
vector<pair<int,int>> queries[maxn]; // for each left endpoint l, contains a vector of pairs (r, idx)

struct BIT{
    long long abi[maxn]{};
    BIT(){
        fill(abi, abi + maxn, 0);
    }
    long long query(int pos){
        long long res = 0;
        for(; pos > 0; pos -= pos &-pos){
            res += abi[pos];
        }
        return res;
    }
    void upd(int pos, long long val){
        for(; pos < maxn; pos += pos &-pos){
            abi[pos] += val;
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int T;
    cin >> T;
    vector<long long> ans(T);
    for(int i = 0; i < T; i++){
        int l, r;
        cin >> l >> r;
        queries[l].emplace_back(r, i);
    }

    // precomputing for each j, a sorted vector with j's divisors
    for(int i = 1; i < maxn; i++){
        for(int j = i; j < maxn; j += i)
            divisors[j].push_back(i);
    }

    BIT T1; // auxiliary fenwick that will be helpful to do queries fast

    for(int a = maxn - 1; a >= 1; a--){
        for(int c = a * 2; c < maxn; c += a) {

            int l = upper_bound(divisors[c].begin(), divisors[c].end(), a) - divisors[c].begin();
            int r = lower_bound(divisors[c].begin(), divisors[c].end(), c) - divisors[c].begin();

            if (l < r) {
                T1.upd(c, r - l);
            }
        }
        for(int c2 = a * 2; c2 < maxn; c2 += a) {
            if(c2 & 1)
                continue;
            int c = c2 >> 1;
            int l = upper_bound(divisors[2*c].begin(), divisors[2*c].end(), max(a, c - a)) - divisors[2*c].begin();
            int r = lower_bound(divisors[2*c].begin(), divisors[2*c].end(), c) - divisors[2*c].begin();

            if(l < r){
                T1.upd(c, r - l);
            }
        }

        int l = a;
        for(auto [r, idx]:queries[l]){
            ans[idx] = choose3(r - l + 1) - T1.query(r);
        }
    }

    for(int i = 0; i < T; i++){
        cout << ans[i] << '\n';
    }

    return 0;
}