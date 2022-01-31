#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;
// Adjacency Matrix
int N = 10;
vector<vector<bool>> a(N, vector<bool>(N));
// Initialise the boolean vector
void initialise()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			a[i][j] = false;
		}
	}
}
// Adjacency List
vector<vector<int>> v(N);
int main()
{
	// Nodes
	int nodes; cin >> nodes;
	// Edges
	int edges; cin >> edges;
	// Adjacency Matrix
	/*
	initialise();
	while(edges--)
	{
		// two integers -> i, j ----> edge from i to j
		int i, j; cin >> i >> j;
		a[i][j] = true;
	}
	// Verification
	assert(a[1][2] == true);
	assert(a[3][2] == false);
	cout << "All Cases Passed !";
	*/

	// Adjacency List
	for (int i = 0; i < edges; ++i)
	{		

	// two integers -> t, w ----> edge from t to w
		int t, w;
		cin >> t >> w;
		v[t].push_back(w); //Insert w in adjacency list of t
	}

	for (int i = 0; i < N; ++i)
	{
		cout << "Adjacency List of vertex " << i << " is : ";
		for (int j = 0; j < v[i].size(); ++j)
		{
			cout << v[i][j] << ", ";
		}
		cout << endl;
	}
	return 0;
}
// Input file
// 4 // nodes
// 5 //edges
// 1 2 //showing edge from node 1 to node 2
// 2 4 //showing edge from node 2 to node 4
// 3 1 //showing edge from node 3 to node 1
// 3 4 //showing edge from node 3 to node 4
// 4 2 //showing edge from node 4 to node 2
