#include <iostream>
using namespace std;

// Overlapping SubProblems

int dp[100] {0};
int catalan(int n)
{
	if(n == 0) // Base Case
	{
		return 1;
	}
	if(dp[n] != 0)
	{
		return dp[n];
	}
	int ans = 0;
	for(int i = 1; i <= n; ++i)
	{
		ans += catalan(i - 1) * catalan(n - i);
	}
	dp[n] = ans;
	return ans;
}
// You can also (2nCn / (n + 1))
int main()
{
	for(int i = 1; i <= 10; ++i)
	{
		cout << catalan(i) << '\n';
	}
	return 0;
}