// Ternary Search
// Brief -> Similiar to Binary Search but it divides array into three parts instead of two parts
// Time Complexity -> O(log3(n))
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int ternarySearch(vector<int> & v, int key)
{
	sort(v.begin(), v.end());
	// Dividing into 3 parts
	int s = 0, e = ((int)v.size() - 1);
	while(s <= e)
	{
		int mid1 = (s + (e - s) / 3);
		int mid2 = (e - (e - s) / 3);
		// Now array is divided into 3 parts as follows

		// s ...... mid1 .... mid2 ..... e
		if(v[mid1] == key)
		{
			return mid1;
		}

		if (v[mid2] == key)
		{
			return mid2;
		}

		if(key < v[mid1])
		{
			e = mid1 - 1;
		}
		else if (key > v[mid2])
		{
			s = mid2 + 1;
		}
		else
		{
			s = mid1 + 1;
			e = mid2 - 1;
		}
	}
	return -1;
}
int main()
{
	vector<int> v = {1, 2, 3, 5, 4};
	cout << ternarySearch(v, 4);
	return 0;
}