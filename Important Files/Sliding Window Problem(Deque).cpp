// You are given a array. You are also given a integer k. You need to tell maximum number in every
// contiguous sub-array of size k
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	int k;
	cin >> k;
	deque<int> dq; // I will store indices in this
	// Processing first k elements
	for (int i = 0; i < k; ++i)
	{
		while (!dq.empty() && (a[i] > a[dq.back()]))
		{
			dq.pop_back();
		}
		dq.push_back(i);
	}
	// Processing remaining elements
	for (int i = k; i < n; ++i)
	{
		cout << a[dq.front()] << " ";

		// 1) Remove all those indices which are not present in present sub-array(Contraction)
		while (!dq.empty() && (dq.front() <= i - k))
		{
			dq.pop_front();
		}

		// 2) Remove indices which are present in window and are not useful
		while (!dq.empty() && (a[dq.back()] <= a[i]))
		{
			dq.pop_back();
		}

		// 3) Add new element(Expansion)
		dq.push_back(i);
	}
	cout << a[dq.front()];
	return 0;
}