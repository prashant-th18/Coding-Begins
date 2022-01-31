#include <bits/stdc++.h>
using namespace std;
int N = 1e3 + 1;
vector<vector<bool>> v(N, vector<bool>(N));
void initialise()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			v[i][j] = false;
		}
	}
}
int main()
{
	int n, m; cin >> n >> m;
	initialise();
	while(m--)
	{
		int a, b; cin >> a >> b;
		v[a][b] = true;
		v[b][a] = true;
	}
	int q; cin >> q;
	while(q--)
	{
		int a, b; cin >> a >> b;
		if(v[a][b])
		{
			cout << "YES\n";
		}
		else cout << "NO\n";
	}
	return 0;
}
