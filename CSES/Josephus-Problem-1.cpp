#include<bits/stdc++.h>
using namespace std;
int n;
int inc(set<int>& st, int s)
{
   auto it = st.lower_bound(s);
   if(it == st.end()) it = st.begin();
   return *it;
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(nullptr);
    cin >> n;
    set<int> st;
    for(int i = 0; i < n; ++i) st.insert(i);
    int s = 0;
    while((st.size()) != 0)
    {
        auto it = st.upper_bound(s);
        if(it == st.end()) it = st.begin();
        cout << (*it) + 1 << ' ';
        s = *it;
        st.erase(it);
        s = inc(st, s);
    }
    return 0;
}
