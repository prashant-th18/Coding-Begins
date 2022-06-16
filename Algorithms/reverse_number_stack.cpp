/*   
			Reverse number using stack 
												*/
#include<bits/stdc++.h>
using namespace std;
int number(int num)
{
	for(int i = 1;;i++)
	{
		int z = pow(10,i);
		if (num/z==0)
		{
			return i;
		}
	}
}
int reverse_num(int num)
{
	stack<int> temp;
	
	for (int i = number(num); i >0; i--)
	{
		int z = pow(10,i-1); // 1234 1234
		int var = num/z;
		temp.push(var%10);
	}
	int result = 0;
	while(!temp.empty())
	{
		result = result*10 + temp.top();
		temp.pop();
	}
	return result;
}
int main()
{	
	int num;
	cin>>num;
	cout<<reverse_num(num);
	return 0;
}