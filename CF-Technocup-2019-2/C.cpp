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
        ll a, b, ra, rb; cin >> a >> b; ra = a, rb = b;
        if(a + b == 0)
        {
            cout << 0 << '\n' << 0; return 0;
        }
        ll sum = a + b;
        ll last = 1, temp = 1;
        set<ll> pq;
        while(temp <= sum)
        {
            pq.insert(last++);
            temp += last;
        }
        vector<ll> n, m;
        // Assuming a > b
        if(a < b) swap(a, b);
        while(a > 0 && !pq.empty())
        {
            if(*pq.rbegin() <= a)
            {
                n.push_back(*pq.rbegin());
                a -= n.back();
                pq.erase(*pq.rbegin());
            }
            else
            {
                n.push_back(a);
                pq.erase(a);
                a = 0;
            }
        }
        for(const auto& val : pq) m.push_back(val);
        if(ra < rb) swap(m, n);
        auto print = [&](vector<ll>& ttemp) -> void
        {
            cout << sz(ttemp) << '\n';
            for(auto val : ttemp) cout << val << ' ';
            cout << '\n';
        };
        print(n); print(m);
        cout << '\n';
    }
    return 0;
}
// -> Keep It Simple Stupid!
