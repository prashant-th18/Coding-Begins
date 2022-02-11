#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define sz(x) ((int)x.size())
#define ff first
#define ss second
#define all(x) begin(x), end(x)
const int MOD = 1e9 + 7;
// *-> KISS*
vector<bool> vis;
vector<int> dis;
vector<int> v;
void do_it(int index, int ind)
{
    vis[index] = true;
    dis[index] = 1 + dis[ind];
}
void bfs()
{
    queue<int> q; q.push(0);
    vis[0] = true; dis[0] = 0;
    while(!q.empty())
    {
        auto index = q.front(); q.pop();
        if(index != 0 && !vis[index - 1])
        {
            do_it(index - 1, index); q.push(index - 1);
        }
        if(index + 1 < sz(v) && !vis[index + 1])
        {
            do_it(index + 1, index); q.push(index + 1);
        }
        if(!vis[v[index]])
        {
            do_it(v[index], index); q.push(v[index]);
        }
    }
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int test = 1;
    //cin >> test;
    for(int t_ = 0; t_ < test; t_++)
    {
        int n; cin >> n;
        v.assign(n, 0);
        vis.assign(n, false);
        dis.assign(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            --v[i];
        }
        bfs();
        for(int i = 0; i < n; ++i) cout << dis[i] << ' ';
        cout << '\n';	
    }
    return 0;
}
// -> Keep It Simple Stupid!
