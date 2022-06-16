/*
			find all words which start with prefix(not duplicacy)
														*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int num;
	cin>>num;
	multimap<string, string> mp;
	set<string> st;
	while(num--)
	{
		string var;
		cin>>var;
		auto [it,success] = st.insert(var);
		if(success == true)
	{
		for (int i = 1; i <= (int)var.size(); ++i)
		{
			string z = var.substr(0,i);
			mp.insert({z,var});
		}
	}
	}
	int q;
	cin>>q;
	while(q--)
	{
		string variable;
		cin>>variable;
		set<string> st1;
		auto [it_begin,it_end] = mp.equal_range(variable);
		for(auto i = it_begin;i!=it_end;i++)
		{
			st1.insert(i->second);
		}
		for(auto val1 : st1)
		{
			cout<<val1<<" ";
		}
		cout<<endl;
		
	}
	return 0;
}