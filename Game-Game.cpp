#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	cout << fixed << setprecision(0);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//////
	int t = 1;
	// cin >> t; // We are taking test cases
	while (t--)
	{
		int n; cin >> n;
		vector<pair<int, int>> v(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> v[i].first;
			v[i].second = i;
		}
		auto f = [&](pair<int, int> a, pair<int, int> b)
		{
			return a.first > b.first;
		};
		sort(v.begin(), v.end(), f);
		vector<int> pos(n, 0);
		for(int i = 0; i < n; ++i)
		{

		}
	}
	return 0;
}