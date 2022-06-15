//https://www.hackerearth.com/problem/algorithm/teachers-dilemma-3-00955296/

#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, m; cin >> n >> m;
    vector<int> par(n + 1, 1);
    // if(par[i] == i), then "i" is the main parent of it's whole set
    // So, my first approach for this problem is that, make a "find function" which gives the parent of the 
    // set in which this node is present
    // Now since I am getting a, b at the same time, I will use "find" function for both of these and then
    // I will apply the "union" method on the nodes found after applying "find" function
    // "union" will merge both of them and will make one of the parent, a child of another parent
    // Implement -> 
    auto find1 = [&](int node) {
        while(node != parent[node]) {
            node = parent[node];
        }  
        return node;
    };
    auto union1 = [&](int a, int b) {
        parent[a] = b;
    };
    // Although now I may be able to get that how many disjoint sets are there (by looking at indices where
    // par[i] == i), but can't guess it right on all cases that how many nodes are linked to this set in constant
    // time
    //
    // So because of this, we implemented in another way
    par.assign(n + 1, -1);
    // if(par[i] < 0), this means that, this node is a parent of a set, and "magnitude" of this number tells 
    // number of nodes contained in this set
    auto find2 = [&](int node) {
        while(par[node] > 0) {
            node = par[node];
        }
        // Since par[node] < 0 now, therefore I have reached the parent of the set
        return node;
    };
    auto union2 = [&](int a, int b) {
          par[a] += par[b];
          par[b] = a;
          // What have I done here?
          // Suppose a node is having total 3 nodes in it's set and b is having 2 total nodes
          // => par[a] = -3, par[b] = -2
          // par[a] += par[b]
          // So, now in the above line I said that, b is going to be a child of 'a'
    };
    // Now, I can get to know that how many disjoint sets are there by looking at those indices where (par[i] < 0)
    // and for each set, I can also get to know how many nodes it contain by -> abs(par[i]);
    //
    // / But If I applied this method to the question, it will TLE, because in the worst case scenario
    // find function can take n^2 time
    return 0;
}
