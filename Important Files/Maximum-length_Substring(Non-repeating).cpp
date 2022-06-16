// You are given a string, you have to find maximum length of sub-string which has no repeating characters
#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin >> s;
	int max_len = 1; // It will be used to store maximum length
	int cur_len = 1; // It will be used to store current length og sliding window

	vector<int> visited(256, -1); // This vector will tell the nearest index of character 
								  // and -1 will tell that it is not present till now.

	visited[s[0]] = 0;
	for(int i = 1; i < s.size(); ++i)
	{
		int last_occ = visited[s[i]];

		// Expansion (Either character is not present till now or 2) Is not present in window)
		if(last_occ == -1 || last_occ < i - cur_len)
		{
			++cur_len;
			max_len = max(max_len, cur_len);
		}
		else // Contraction
		{
			max_len = max(max_len, cur_len);
			cur_len = i - last_occ;
		}

		// Marks the character index on which we are present
		visited[s[i]] = i;
	}
	cout << max_len;
	return 0;
}