#ifdef LOCAL
    #define _GLIBCXX_DEBUG
#endif
// #pragma GCC optimize("O3")
// #pragma GCC target("popcnt")
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
#define MOD 100000000;
typedef long long ll;
typedef long double ld;
#define sz(s) ((int)s.size())
#define all(v) begin(v), end(v)
#define ff first
#define ss second

// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

// *-> KISS*
int solve() {
    // subtasks
    // any 4 select (distinct)
    // try to make a arrangement such that these 4 make rectangle and square
    vector<pair<ll, ll>> v;
    for (int i = 0; i < 8; i++) {
        ll a, b; cin >> a >> b;
        v.push_back({a, b});
    }
    auto perpen = [&](int xa, int ya, int xb, int yb, int xc, int yc) -> bool
    {
            // xa, ya     xb, yb      xc, yc
            // (ya - yb) / (xa - xb)
            // (yc - yb) / (xc - xb)
            ll a1 = (ya - yb), a2 = (yc - yb);
            ll b1 = (xa - xb), b2 = (xc - xb);
            if(b1 == 0)
            {
                if(a2 == 0) return true;
                else return false;
            }
            else if(b2 == 0)
            {
                if(a1 == 0) return true;
                else return false;
            }
            else
            {
                int one = (ll)(ya - yb) * (yc - yb);
                int two = -1 * (ll)(xa - xb) * (xc - xb);
                if(one == two) return true;
                else return false;
            }
    };
    auto ind = [&](int index) -> int
    {
        return (index) % 4;  
    };
    auto dis1 = [&](int a, int b, int c, int d) -> ll
    {
          return ((ll)(a - c) * (a - c) + (ll)(b - d) * (b - d));
    };
    auto maybe = [&](const auto& other) -> ll
    {
        vector<pair<int, int>> vec;
        for (int i = 0; i <= 3; i++) {
            vec.push_back(v[other[i]]);
        }
        int k = 0;
         for(int i = 0; i <= 3; ++i)
         {
             if(perpen(vec[i].ff, vec[i].ss, vec[ind(i + 1)].ff, vec[ind(i + 1)].ss, vec[ind(i + 2)].ff, vec[ind(i + 2)].ss))
             {}
             else
             {
                 return 0;
             }
         }
            int i = 0;
                ll a = dis1(vec[i].ff, vec[i].ss, vec[ind(i + 1)].ff, vec[ind(i + 1)].ss);
                ll b = dis1(vec[ind(i + 1)].ff, vec[ind(i + 1)].ss, vec[ind(i + 2)].ff, vec[ind(i + 2)].ss);
                ll c =  dis1(vec[ind(i + 1)].ff, vec[ind(i + 1)].ss, vec[ind(i + 3)].ff, vec[ind(i + 3)].ss);
                ll d = dis1(vec[ind(i)].ff, vec[ind(i)].ss, vec[ind(i + 2)].ff, vec[ind(i + 2)].ss);
                if(c == d)
                {
                    if(a == b) k = 2;
                    else k = 1;
                }
                else k = 0;
         return k;
    };
    auto check = [&](auto& one, auto& two) -> int
    {
        // at least one of them should be a square
        
        // one ->
        int f1 = 0, f2 = 0; // 0 -> nothing, 2 -> means square, 1 -> rectangle
        sort(one.begin(), one.end());
        do
        {
            int ahead = maybe(one);
            if(ahead == 2)
            {
                f1 = 2; break;
            }
            else if(ahead == 1) f1 = 1;

        } while(next_permutation(all(one)));
        
        sort(two.begin(), two.end());
        do
        {
            int ahead = maybe(two);
            if(ahead == 2)
            {
                f2 = 2; break;
            }
            else if(ahead == 1) f2 = 1;

        } while(next_permutation(all(two)));
        
        if(f1 != 0 && f2 != 0 && (f1 == 2 || f2 == 2))
        {
            return (f1 == 2) ? (1) : (2);
        }
        else return 0;
    };
    auto print = [&](const auto& vv) -> void
    {
        for(auto val : vv) cout << val + 1 << ' ';
        cout << '\n';
    };
    // ........ => any 4 bits
    for(int i = 15; i <= 255; ++i)
    {
        if(__builtin_popcount(i) == 4)
        {
            vector<int> one, two; // one => set, two => unset
            for(int k = 0; k <= 7; ++k)
            {
                if((1 << k) & i)
                {
                    one.push_back(k);
                }
                else
                {
                    two.push_back(k);
                }
            }
            assert(sz(one) == 4);
            assert(sz(two) == 4);
            int flag = check(one, two);
            if(flag != 0)
            {
                cout << "YES\n";
                if(flag == 1)
                {
                    print(one); print(two);
                }
                else
                {
                    print(two); print(one);
                }
                return 0;
            }
        }
    }
    cout << "NO\n";
    return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TET = 1;
    //cin >> TET;
    cout << fixed << setprecision(6);
    for (int i = 1; i <= TET; i++) {
#ifdef LOCAL
        cout << "##################" << '\n';
#endif
        if (solve())
        {
            break;
        }
        cout << '\n';
    }
#ifdef LOCAL
    cout << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
}
// -> Keep It Simple Stupid!
