/*
Union By Rank ->
While merging (performing union operation), "set" with higher number of elements should be present.
*/
// It works on the basis that, If i have to merge two sets, then they will be merged on the basis of their size,
// i.e. one whose size is greater will become the parent of other one

#include<bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    vector<int> par(n + 1, -1);
    vector<int> R(n + 1, 1);
    // R stands for rank, i.e. what is the size of set having vertex "i" is given by R[i]
    auto find = [&](int node) {
        // Apply Path Compression here
        vector<int> t;
        while(par[node] > 0) {
            t.push_back(node);
            node = par[node];
        }
        for (int i = 0; i < sz(t); i++) {
            par[t[i]] = node;
        }
        return node;
    };
    auto un = [&](int a, int b) {
          a = find(a);
          b = find(b);
          if(a == b) return;

          if(R[a] > R[b]) {
              R[a] += R[b];
              par[b] = a;
          }
          else {
              R[b] += R[a];
              par[a] = b;
          }
    };
    // Now, we are optimal
    return 0;
}
