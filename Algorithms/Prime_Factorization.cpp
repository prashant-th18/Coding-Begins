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
	for (ll d = 2; d * d <= n; d++)
	{
		while (n % d == 0)
		{
			factorization.push_back(d);
			n /= d;
		}
	}
	if(n > 1)
	{
		factorization.push_back(n);
	}
	for (auto val : factorization) cout << val << " ";
	return 0;
}