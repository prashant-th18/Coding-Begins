#include<bits/stdc++.h>
using namespace std;
int main()
{
	vector<int> mp(26, 0);
	string s;
	cin >> s;
	int cnt = 0;
	int ch = -1;
	for (int i = 0; i < (int)s.size(); ++i)
	{
		++mp[s[i] - 65];
	}
	for (int i = 0; i < 26; ++i)
	{
		if (mp[i] & 1)
		{
			ch = i;
			cnt++;
		}
	}
	if (cnt > 1)
	{
		cout << "NO SOLUTION";
		return 0;
	}
	string z = string((int)s.size(), '.');
	int si = 0, ei = (int)z.size() - 1;
	for (int i = 0; i < 26; ++i)
	{
		if(!(mp[i] & 1))
		{
			for (int j = 0; j < mp[i]; ++j)
			{
				if(j & 1)
				{
					z[si++] = (char)(65 + i);
				}
				else
				{
					z[ei--] = (char)(65 + i);
				}
			}
		}
	}
	if (ch != -1)
	{
		while(si <= ei)
		{
			z[si++] = (char)(65 + ch);
		}
	}
	cout << z;
	return 0;
}