#include<iostream>
using namespace std;
bool is_prime(int num)
{
	int i = num/2;
	while(i>1)
	{
		if (num%i==0)
		{
			return 0;
		}
		i--;
	}
	return 1;
}
int nth_prime(int n)
{
	int cnt=0;
	for (int i = 2;; ++i)
	{
		if (is_prime(i) == 1)
		{
			cnt++;
		}
		if (cnt==n)
		{
			return i;
		}
	}
}
int main()
{
	int n;
	cin>>n;
	cout<<nth_prime(n);
	return 0;
}