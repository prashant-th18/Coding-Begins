#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define all(x) begin(x), end(x)
#define ff first
#define ss second
#define sz(x) (int)x.size()
int main() {

  int n, m; cin >> n >> m;
  vector<ll> v(m);
  map<ll, ll> mp;
  for(int i = 0; i < m; ++i) {
      ll l, r; cin >> l >> r;
      v[i] = l;
      mp[l] = r;      
  }
  sort(all(v));
  ll s = 1, e = (ll)2e18;
  ll ans = 0;
  while(s <= e) {
    ll mid = (s + e) >> 1;
    ll f = v[0];
    bool flag = true;
    for(int i = 1; i < n; ++i) {
      ll nf = f + mid;
      int in = upper_bound(all(v), nf) - begin(v);
      --in;
      assert(in >= 0);
      if(mp[v[in]] >= nf) {
        f = nf;
        // OK
      }
      else {
        ++in;
        if(in >= sz(v)) {
          flag = false; break;
        }
        else f = v[in];
      }
    }
    if(flag) {
      ans = mid; s = mid + 1;
    }
    else e = mid - 1;
  }
  cout << ans;
  return 0;

}