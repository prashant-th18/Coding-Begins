#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define sz(x) ((int)x.size())
#define ff first
#define ss second
#define all(x) begin(x), end(x)
const int MOD = 1e9 + 7;
// *-> KISS*

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int test = 1;
    //cin >> test;
    for(int t_ = 0; t_ < test; t_++)
    {
        int n; cin >> n;
        vector<int> one, two;
        for (int i = 0; i < n; i++) {
            int a, b; cin >> a >> b;
            if(a == 1) one.push_back(b);
            else two.push_back(b);
        }
        // i -> 2's, how many 1's we can place at the top
        sort(one.begin(), one.end()); sort(two.begin(), two.end());
        ll two_sum = 0, ans = sz(one) + 2 * sz(two);
        debug(one);
        debug(two);
        for(int i = 0; i < sz(two); ++i)
        {
            // i + 1 -> how many two's taken
            ll temp = sz(one) + 2 * sz(two);
            temp -= 2 * (i + 1);
            two_sum += two[i];
            // temp - j >= two_sum + {sum of first j elements of one}
            if(temp >= two_sum)
            {
                ll cnt = temp, till_now_one = 0;
                for(int j = 0; j < sz(one); ++j)
                {
                    // j + 1
                    till_now_one += one[j];
                    if(temp - (j + 1) >= two_sum + (till_now_one))
                    {
                        cnt = temp - (j + 1);
                    }
                }
                ans = min(ans, max(2LL, cnt));
                debug(ans);
                debug(i);
            }
        }
        auto fun = [&](ll temp, ll extra = 0) -> ll
        {
            ll till_now = 0, cnt = temp;
            for(int j = 0; j < sz(one); ++j)
            {
                till_now += one[j];
                if(temp - (j + 1) >= extra + till_now)
                {
                    cnt = temp - (j + 1);
                }
            }
            ll tt = (extra != 0) ? 2LL : 1LL;
            ans = min(ans, tt);
        };
        ll temp = sz(one) + 2 * sz(two), till_now = 0;
        for(int j = 0; j < sz(one); ++j)
        {
            till_now += one[j];
            if(temp >= till_now) ans = min(ans, max(1LL, temp - j - 1));
            debug(ans);
        }
        cout << ans;
        cout << '\n';	
    }
    return 0;
}
// -> Keep It Simple Stupid!
