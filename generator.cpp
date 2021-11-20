#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
int main()
{
	int n = 100;
	cout << n << '\n';
	while(n--)
	cout << uid(0, 3) << ' ';
	return 0;
}