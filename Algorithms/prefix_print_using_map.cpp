/*
			find all words which start with prefix
														*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int num;
	cin>>num;
	multimap<string, string> mp;
	while(num--)
	{
		string var;
		cin>>var;
		for (int i = 1; i <= (int)var.size(); ++i)
		{
			string z = var.substr(0,i);
			mp.insert({z,var});
		}
	}
	int q;
	cin>>q;
	while(q--)
	{
		string variable;
		cin>>variable;
		auto [it_begin,it_end] = mp.equal_range(variable);
		for(auto i = it_begin;i!=it_end;i++)
		{
			cout<<i->second;
			cout<<" ";
		}
		cout<<endl;
		
	}
	return 0;
}