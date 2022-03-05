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
    cin >> test;
    for(int t_ = 0; t_ < test; t_++)
    {
        int n; cin >> n;
        vector<int> v(n);
        unordered_set<int> st;
        for (int &val : v) {
            cin >> val;
            --val;
            st.insert(val);
        }
        for(int i = 0; i < 30; ++i)
        {
            int rem = i % 7;
            if(5 <= rem) st.insert(i);
        }
        cout << sz(st);
        cout << '\n';	
    }
    return 0;
}
// -> Keep It Simple Stupid!
