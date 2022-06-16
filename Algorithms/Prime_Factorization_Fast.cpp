#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	// Prime Factorisation of number n
	ll n;
	cin >> n;
	vector<ll> factorization;
	factorization.push_back(1);
	for (auto val : {2, 3, 5})
	{
		while (n % val == 0)
		{
			factorization.push_back(val);
			n /= val;
		}
	}
	// for primes from & onwards there's a pattern
	int increment[8] {4, 2, 4, 2, 4, 6, 2, 6};
	int k = 0;
	for (ll i = 7; i * i <= n; i += increment[k++])
	{
		while (n % i == 0)
		{
			factorization.push_back(i);
			n /= i;
		}
		if (k == 8) k = 0;
	}
	if (n > 1)
	{
		factorization.push_back(n);
	}
	for (auto val : factorization) cout << val << " ";
	return 0;
}