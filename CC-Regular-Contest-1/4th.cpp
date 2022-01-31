#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define sz(x) ((int)x.size())
#define ff first
#define ss second
#define all(x) begin(x), end(x)
// *-> KISS*
int32_t main() {
    int test; cin >> test;
    while(test--)
    {
        int n; cin >> n;
        vector<ll> or_a(n); // Taking input of OR array
        for (ll &val : or_a) {
            cin >> val;
        }
        vector<ll> and_a(n); // Taking input of AND array
        for (ll &val : and_a) {
            cin >> val;
        }
        vector<ll> xor_a(n);
        for(int i = 0; i < n; ++i)
        {
            // xor_a[i] = or_a[i] - and_a[i];
            // < 0 impossible RIGHT
            // Bit by Bit
            bool flag = true;
            for(ll j = 0; j < 31; ++j)
            {
                ll and_set = and_a[i] & (1LL << j);
                ll or_set = or_a[i] & (1LL << j);
                if(and_set != 0 && or_set == 0)
                {
                    flag = false; break;
                }
            }
            if(flag)
            {
                xor_a[i] = or_a[i] - and_a[i];
            }
            else xor_a[i] = -1;
        }
        for(int i = 0; i < n; ++i)
        {
            cout << xor_a[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
// -> Keep It Simple Stupid!
