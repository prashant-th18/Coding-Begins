// Tarjan's Algorithm
// Algorithm to find out strongly connected components
#include<bits/stdc++.h>
using namespace std;
int N = 1e5 + 1;
vector<vector<int>> v(N); // Adjacency List
vector<bool> vis(N, false); // Visited Vector
vector<bool> onStack(N, false); // onStack keeps true for the nodes which are visited by "dfs" and who may become
// part of single Strongly Connected Component
vector<int> in(N), low(N);
// in-Time and low-Time arrays which will be used to check whether node belongs to same SCC.
stack<int> st; // Keeps nodes which may be the part of same SCC.
int timer = 0, scc = 0;
void dfs(int node)
{
    vis[node] = true;
    in[node] = low[node] = timer++;
    st.push(node);
    onStack[node] = true;
    for(const auto& val : v[node])
    {
        if(vis[val] && onStack[val])
        {
            low[node] = min(low[node], in[val]);
        }
        else if(!vis[val])
        {
            dfs(val);
            if(onStack[val])
            low[node] = min(low[node], low[val]);
        }
    }
    if(in[node] == low[node])
    {
        ++scc;
        cout << "SCC # " << scc << '\n';
        while(1)
        {
            int tt = st.top(); st.pop();
            onStack[tt] = false;
            cout << tt << ' ';
            if(tt == node) break;
        }
        cout << '\n';
    }
}
int main()
{
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        v[a].push_back(b);
    }
    for(int i = 1; i <= n; ++i)
    {
        if(!vis[i])
        {
            dfs(i);
        }
    }
    return 0;
}
/*
Tarjan's Algorithm ->
So basically, hm kisi node pr dfs call krte hai, after that, agr hme uske kuch children visited milte hai toh agr
ye children "onStack" pr true paae gye mtlb ki abhi tk hme puri trah se pta nhi lga hai ki strongly connected
component kis kis ko include krta hai toh hme apne low time ko agle vaale ke in time se minimize krne ki 
koshish krte hai. On the other hand agr vo unvisited hai toh phle lgai dfs call, fir dekha ki agr vo "onStack" prr
true hai ki nhi. If no, then mtlb jispr call lgai thi vo kisi apne SCC mai included hai nhi toh vo bhi usi SCC mai
include hoga jisme hm hai toh hm apna low time uske through minimize krne ki koshish krte hai jis se ye dhyaan 
rhe ki hm konsi sbse km in time vaali node tk pahunche hue hai.

Then agr koi esi node hai jiske liye saari nodes pr traverse krke bhi in-Time and low-Time same aata hai that means
abhi tk jitne bhi "st" mai present hai vo saare abhi ki present node ke SCC ke part hai toh hm stack mai tb tk pop krke print krte rehte hai jb tk present node pop na hojae aur sbhi ki "onStack" jin jin ko pop kia unko false krdete
hai.
is trah se SCC's ka pta chlta rhta hai
*/
