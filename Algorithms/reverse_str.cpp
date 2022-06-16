/*
			reverse string
								*/

#include<iostream>
using namespace std;
string func(const string &str)
{
	char temp[str.size()+1];
	for (int i = 0; i < str.size(); ++i)
	{
		temp[i] = str[str.size()-i-1]; 
	}
	return temp;
}
int main()
{
	string name,get;
	cin>>name;
	get = func(name);
	cout<<get<<endl;
	return 0;
}