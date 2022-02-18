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
        vector<int> capacity(n);
        set<int> st;
        for (int i = 0; i < n; i++) {
            cin >> capacity[i];
            st.insert(i);
        }
        vector<int> filled(n, 0);
        int q; cin >> q;
        while(q--)
        {
            int a; cin >> a;
            if(a == 1)
            {
               int p, x; cin >> x >> p; --x;
               auto it = st.lower_bound(x);
               while(it != st.end())
               {
                   int left = capacity[*it] - filled[*it];
                   if(p < left)
                   {
                       filled[*it] += p; p = 0;
                       break;
                   }
                   else if(p == left)
                   {
                       filled[*it] += p; p = 0; st.erase(it);
                       break;
                   }
                   else
                   {
                       filled[*it] = capacity[*it];
                       st.erase(it);
                       p -= left;
                       it = st.lower_bound(x);
                   }
               }
            }
            else
            {
                int ind; cin >> ind; --ind;
                cout << filled[ind] << '\n';
            }
        }
        cout << '\n';	
    }
    return 0;
}
// -> Keep It Simple Stupid!
