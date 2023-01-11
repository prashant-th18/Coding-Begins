#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
template<typename T>
T binexp(T a, T b) {
	T ans = 1;
	while (b) {
		if (b & 1) {
			ans = 1LL * ans * a % MOD;
		}
		a = 1LL * a * a % MOD;
		b >>= 1;
	}
	return ans;
}
ll modinv(ll x) {
	return binexp(x, MOD - 2);
}
int main(int argc, char *argv[]) {
	// Euler Totient Function calculates the number of integers less than 'n' which are co-prime to 
	// 'n'
	// Or, in other words, pi[n] = Integers less than n such that for each of that integers(say 'x')
	// gcd(x, n) == 1.
	// Now, How to calculate Euler Totient Function??
	// pi[n] = n * product of {1 - 1 / p} where p iterates over all the prime factors of n.
	// pi[6] = 6 * (1 - 1 / 2) * (1 - 1 / 3)
	// => pi[6] = 2;
	//
	// Euler Totient Theorem
	// Suppose we want to calculate a^b mod M.
	// So, Theorem says that,
	// a ^ (b % pi[M]) mod M gives the same result.
	ll n; cin >> n;
	ll ans = n; // pi[n]
	// Suppose we have stored prime factors of number 'n' in a vector.
	vector<int> prime;
	for(int i = 0; i < prime.size(); ++i) {
		ans = ans * (1 - modinv(prime[i]) + MOD) % MOD;
	}
	cout << ans;
	return 0;
}
