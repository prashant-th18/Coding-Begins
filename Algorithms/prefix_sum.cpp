#include<iostream>
using namespace std;
int z = 0;
int sum(int arr[],int len,int start)
{
	if (start==-1)
	{
		return 0;
	}
	else
	{
		
		return arr[start-1] + sum(arr,len,start-1);
	}
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	int m;
	cin>>m;
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}

	cout<<sum(arr,n,m);
	return 0;
}