#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define sz(x) ((int)x.size())
#define ff first
#define ss second
#define all(x) begin(x), end(x)
// *-> KISS*

template<class Fun>
class y_combinator_result {
    Fun fun_;
public:
    template<class T>
    explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args>
    decltype(auto) operator()(Args &&...args) {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};
template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}
// use -> auto gcd = y_combinator([](auto gcd, int a, int b) -> int { return b == 0 ? a : gcd(b, a % b);});

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int test = 1;
    //cin >> test;
    for(int t_ = 0; t_ < test; t_++)
    {
        int n, m; cin >> n >> m;
        vector<vector<int>> v(n + 1);
        vector<bool> vis(n + 1, false);
        for (int j = 0; j < m; j++) {
            int a, b; cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        auto dfs = y_combinator([&](auto f, int node) -> void
        {
            vis[node] = true;
            for(const auto& val : v[node])
            {
                if(!vis[val]) f(val);
            }
        });
        vector<int> comp;
        for(int i = 1; i <= n; ++i)
        {
            if(!vis[i])
            {
                comp.push_back(i);
                dfs(i);
            }
        }
        cout << sz(comp) - 1 << '\n';
        for(int i = 1; i <= sz(comp) - 1; ++i)
        {
            cout << comp[i] << ' ' << comp[i - 1] << '\n';
        }
    }
    return 0;
}
// -> Keep It Simple Stupid!
