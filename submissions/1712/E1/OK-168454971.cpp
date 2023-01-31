/**
  Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools

  To modify the template, go to Preferences -> Editor -> File and Code Templates -> Other
*/

#include <bits/stdc++.h>

using namespace std;

const int maxn = 4e5 + 5;
int cnt_div[maxn];
vector<int> divisors[maxn];

long long choose2(long long n){ return n * (n - 1) >> 1; }
long long choose3(long long n){ return n * (n - 1) * (n - 2) / 6; }

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    for(int i = 1; i < maxn; i++){
        for(int j = i; j < maxn; j += i){
            cnt_div[j]++;
            divisors[j].push_back(i);
        }
    }

    int T;
    cin >> T;
    while(T--){
        int l, r;
        cin >> l >> r;
        long long ans = 0;
        for(int c = l; c <= r; c++){

            // count the number of pairs (A, B) such that A < B < C and A and B are divisors of C and
            if((int)divisors[c].size() > 2){
                int L = lower_bound(divisors[c].begin(), divisors[c].end(), l) - divisors[c].begin();
                int R = lower_bound(divisors[c].begin(), divisors[c].end(), c) - divisors[c].begin();

                if(L < R)
                    ans += choose2(R - L);
            }

            // count the number of pairs (A, B) such that A < B < C and A + B > C and LCM(A, B, C) = 2 * C
            int p = find(divisors[2 * c].begin(), divisors[2 * c].end(), c) - divisors[2 * c].begin();
            for(int i = 0; i < p; i++){
                int a = divisors[2 * c][i];
                if(a < l) continue;

                int L = upper_bound(divisors[2 * c].begin(), divisors[2 * c].end(), max(c - a, a)) - divisors[2 * c].begin();

                ans += max(0, p - L);
            }
        }

        ans = choose3(r - l + 1) - ans;

        cout << ans << '\n';
    }

    return 0;
}