#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> v;
vector<bool> vis;
int main()
{
    int n, m; cin >> n >> m;
    v.assign(n + 1, vector<int>());
    vis.assign(n + 1, false);
    map<
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    return 0;
}
