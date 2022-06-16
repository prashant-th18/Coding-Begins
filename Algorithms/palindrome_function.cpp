#include<iostream>
using namespace std;
void palindrome(int arr[],int len,int start)
{
	if (arr[start]==arr[len-1])
	{
		if (start>=len)
		{
			cout<<"yes";
			return;
		}
		palindrome(arr,len-1,start+1);
	}
	else
	{
		cout<<"NO\n";
		return;
	}
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	palindrome(arr,n,0);
	return 0;
}