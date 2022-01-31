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
#define MOD 1000000007
typedef long long ll;
typedef long double ld;
#define sz(s) ((int)s.size())
#define all(v) begin(v), end(v)
#define ff first
#define ss second
#ifdef LOCAL
#else
#define debug(x)
#endif
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

// #define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> /* Ordered Set */
// #define ordered_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> /* Ordered MultiSet */
// *-> KISS*
int N = 10000;
int solve() {
    ll n, l, k; cin >> n >> l >> k;
    // coor
    vector<ll> coor(N);
    for (int i = 0; i < n; i++) {
        cin >> coor[i];
    }
    // speed
    vector<ll> speed(N);
    for (int i = 0; i < n; i++) {
        cin >> speed[i];
    }
    vector<pair<ll, ll>> help;
    // sort it
    for (int i = 1; i < n; i++) {
        help.push_back({speed[i], i});
    }
    vector<bool> vis(N, false);
    auto giv_coor = [&](int index) -> ll
    {
      if(index == n)
      {
          return l;
      }
      else
          return coor[index];
    };
    auto again = [&](int real, int index) 
    {
      for(int j = index; j < n; ++j)
      {
          if(!vis[j] || speed[j] < speed[index])
          {
              return speed[real] * (coor[j] - coor[real]);
          }
      }
        return speed[real] * (l - coor[real]);
    };
    auto fun = [&](int index) -> pair<ll, ll>
    {
        bool flag = false;
        for(int i = index - 1; i >= 1; --i)
        {
            if(speed[i] < speed[index])
            {
            return {i, again(i, index + 1)};
            }
            else if(speed[i] == speed[index] && !vis[i])
            {
                return {i, again(i, index + 1)};
            }
        }
        return {0, again(0, index + 1)};
    };
    auto f = [&](const auto& p1, const auto& p2) -> bool
    {
        if(p1.ff != p2.ff)
        {
            vis[max(p1.ff, p2.ff)] = true;
            return p1.ff > p2.ff;
        }
        else
        {
            pair<ll, ll> time1, time2;
            time1 = fun(p1.ss), time2 = fun(p2.ss);
            if(time1.ss > time2.ss)
            {
                vis[p2.ss] = true;
            }
            else
            {
                vis[p1.ss] = true;
            }
            return time1.ss > time2.ss;
        }
    };
    sort(all(help), f);
    vector<bool> mymain(N, false);
    int c = 0;
    while(c < k)
    {
        mymain[(*help.begin()).ss] = true;
        help.erase(help.begin());
        ++c;
    }
    ll now = 0;
    int index = n;
    for(int i = 1; i < n; ++i)
    {
        if(mymain[i] == false)
        {
            index = i; break;
        }
    }
    if(index == n)
    {
        now += speed[0] * (l);
    }
    else
    {
        now += speed[0] * (coor[index]);
    }
    for(int i = index; i < n; ++i)
    {
        int in = n;
        if(mymain[i] == true) continue;
        for(int j = i + 1; j < n; ++j)
        {
            if(mymain[j] == true) continue;
            else
            {
                in = j; break;
            }
        }
        if(in == n)
        {
            now += speed[i] * (l - coor[i]);
        }
        else
        {
            now += speed[i] * (coor[in] - coor[i]);
        }
        debug(now);
    }
    cout << now;
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
