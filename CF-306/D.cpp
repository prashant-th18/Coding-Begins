#include<bits/stdc++.h>
using namespace std;
#define sz(s) (int)s.size()
int main()
{
	int k; cin >> k;
	vector<pair<int, int>> ans;
	if(k == 1)
	{
		cout << "YES\n2 1\n1 2"; return 0;
	}
	if(k == 2)
	{
		cout << "NO";
		return 0;
	}
	int num = k - 1;
	int pres = 2, last = k + 1;
	auto fun = [&](int ff, int zz = 0) -> void{
	for(int i = 0; i < num; ++i)
	{
		ans.push_back({ff, pres});
	    for(int j = 0; j < num - zz; ++j)
		{
			ans.push_back({pres, j + last});
		}
		++pres;
	}
	for(int i = last + 1; i < num + last - zz; i += 2)
	{
		ans.push_back({i, i - 1});
	}
	};
	if(k & 1) 
	{
		cout << "YES\n";
		fun(1);
		ans.push_back({1, last + num});
		int z = last + num;
		pres = last + num + 1; last = pres + k - 1;
		fun(z);
		cout << num - 1 + last << ' ' << sz(ans) << '\n';
		for(auto [x, y] : ans) cout << x << ' ' << y << '\n';
	}
	else
	{
		cout << "NO";
		// fun(1, 1);
		// int llast = num - 1 + last;
		// for(int i = 1; i <= k; ++i)
		// {
		// 	ans.push_back({llast, i});
		// }
		// cout << llast << ' ' << sz(ans) << '\n';
		// for(auto [x, y] : ans) cout << x << ' ' << y << '\n';
	}
    return 0;
}
