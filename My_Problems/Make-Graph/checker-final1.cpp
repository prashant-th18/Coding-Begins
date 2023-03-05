#include <bits/stdc++.h>
#include "testlib.h"
 
using namespace std;
typedef long long ll;
#define sz(x) (int)x.size()

int k;
bool cycle = false;
vector<bool> vis;
vector<vector<int>> adj;
void countCC(int node, int parent = -1)
{
    vis[node] = true;
    for(const auto& val : adj[node])
    {
        if(val == parent) continue;
        else if(!vis[val]) countCC(val, node);
        else
        {
            cycle = true;
        }
    }
}
 
inline ll readAndCheckAnswer(InStream& in) {

    string useless = in.readWord();
    map<string, bool> mp;
    mp["NO"] = mp["No"] = mp["nO"] = mp["no"] = true;
    if(mp.count(useless))
    {
        return -1;
    }
    if(k == 1) return 1;

    ll nodes = in.readLong(1, (ll)1e10 + 1);
    if(nodes > (ll)1e3) {
        in.quitf(_wa, "Nodes are greater than 1000");
    }
    ll edges = in.readLong(1, (ll)1e10 + 1);
    if(edges > (ll)1e4)
    {
        in.quitf(_wa, "Edges are greater than 10000");
    }
    vector<vector<bool>> multiple(nodes + 1, vector<bool>(nodes + 1, false));
    adj = vector<vector<int>>(nodes + 1);
    vis = vector<bool>(nodes + 1);
    for (int i = 0; i < edges; i++) {
        int a = in.readLong(1, nodes);
        int b = in.readLong(1, nodes);
        if(a == b)
        {
            in.quitf(_wa, "Self loops are not allowed");
        }
        if(multiple[a][b])
        {
            in.quitf(_wa, "Multiple edges are not allowed");
        }
        else multiple[a][b] = multiple[b][a] = true;
        
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= nodes; i++) {
        if(sz(adj[i]) != k)
        {
            in.quitf(_wa, "Vertex %d is not having degree equal to %d", i, k);
        }
    }
    int cc = 0;
    for(int i = 1; i <= nodes; ++i)
    {
        if(!vis[i]) countCC(i), ++cc;
    }
    if(cc == 1 && cycle)
    {
        return 1;
    }
    in.quitf(_wa, "Wrong Answer :sad:");
}
int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);
    
    k = inf.readInt();
 
    int ja = readAndCheckAnswer(ans);
    int pa = readAndCheckAnswer(ouf);
 
    if(ja != -1 && pa == -1)
        quitf(_wa, "Jury has the answer but participant has not");
    if(ja == -1 && pa != -1)
        quitf(_wa, "Participant has the answer but jury has not");
 
    quitf(_ok, "Yayy!");
}

