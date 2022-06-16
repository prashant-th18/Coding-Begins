/*
		Reverse a queue using stack 
											*/
#include<iostream>
#include<stack>
#include<queue>
using namespace std;
void reverse_queue(queue<int> &q)
{
	stack<int> temp;
	while(!q.empty())
	{
		temp.push(q.front());
		q.pop();
	}
	while(!temp.empty())
	{
		q.push(temp.top());
		temp.pop();
	}
}
int main()
{
	queue<int> q;
	q.push(10);
	q.push(20);
	q.push(30);
	reverse_queue(q);
	while(!q.empty())
	{
		cout<<q.front()<<" ";
		q.pop();
	}
	return 0;
}