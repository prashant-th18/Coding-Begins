// Calculating Sub-Tree Size in O(N) using DFS
#include <bits/stdc++.h>
using namespace std;
int N = 2e5 + 1;
vector<vector<int>> v(N);
vector<bool> vis(N, false);
vector<int> subSize(N, 0);
int main()
{
    int n; cin >> n;
    // Remember we do this on Trees
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        v[a].push_back(b); v[b].push_back(a);
    }
    int root; cin >> root;
    function<int(int node)> dfs = [&](int node) -> int
    {
        vis[node] = true;
        int current_size = 1;
        for(int child : v[node])
        {
            if(!vis[child])
            {
                current_size += dfs(child);
            }
        }
        subSize[node] = current_size;
        return current_size;
    };
    dfs(root);
    for(int i = 1; i <= n; ++i)
    {
        cout << subSize[i] << ' ';
    }
    return 0;
}
// So Let's See what is Actually Happening ->
// So Hmara Function node as a parameter leta hai, and return ek integer krta hai
// So what is this return thing?
// So hm kya krte hai ki hme pta hai ki agr hm kisi node pr present hai toh us sub-Tree ka size hoga ->
//
// 1 + subtree size of all the children. { Why 1? Because I have to Include Myself. }
// 
// Now Socho mene is node ka toh size chlo nikaal dia aur ek vector mai store bhi krdia
// But Iska jo parent hai uska bhi toh size nikalna tha 
// Kyuki jiski abhi hm baat krr rhe the vo is parent ka hi child hai toh parent ko is node prr firse call 
// krna pdta ye jaan ne ke liye ki iska size kya hai, but kya hm ye hm ise hta skte hai?
// Yes! (How?)
// Tumne just abhi toh child ka size nikala. Vhi size parent ko simply dedo i.e. return krdo and parent use 
// accept krlega aur use firse call ni krni pdegi. 
