#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const int MAXX = (int)1e6 + 1;
const ll MOD = (ll)1e9 + 7;

ll mul(ll a, ll b) {
	return (a * b) % MOD;
}
ll add(ll a, ll b) {
	return (a + b) % MOD;
}
ll sub(ll a, ll b) {
	return (a - b + MOD) % MOD;
}
ll binexp(ll base, ll power) {
	base %= MOD;
	ll ans = 1;
	while(power) {
		if(power & 1) ans = mul(ans, base);

		base = mul(base, base);
		power >>= 1;
	}
	return ans;
}
int main() {
	cin.tie(nullptr) -> sync_with_stdio(false);
	int n; cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; ++i) cin >> v[i];
	vector<int> factors(MAXX, 0);
	for(int i = 0; i < n; ++i) {
		for(int j = 1; j * j <= v[i]; ++j) {
			if(v[i] % j == 0) {
				factors[j]++;
				if(v[i] / j != j) factors[v[i] / j]++;
			}
		}
	}
	ll ans = 0;
	for(ll i = MAXX - 1; i >= 2; --i) {
		if(factors[i] == 0) continue;

		ll how = factors[i];
		ll toAdd = mul(i, mul(how, binexp(2, how - 1)));

		ans = add(ans, toAdd);

		ll toSub = 0;
		vector<ll> fact;
		for(ll j = 2; j * j <= i; ++j) {
			if(i % j == 0) {
				fact.push_back(j);
				if(i / j != j) fact.push_back(i / j);
			}
		}
		for(auto& val : fact) {
			toSub = add(toSub, mul(val, mul(binexp(2, how - 1), how)));
		}
		ans = sub(ans, toSub);
	}
	cout << ans;
	return 0;
}
