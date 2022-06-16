#include<bits/stdc++.h>
using namespace std;
int main()
{
    stack<pair<int, int>> st;
    int n; cin >> n;
    int a[n] {INT_MAX};
    for (int i = 0; i < n; ++i)
    {
        int tt;
        cin >> tt;
        if (i == 0)
        {
            st.push(make_pair(0, tt));
            a[i] = 0;
        }
        else
        {
            if (!st.empty())
            {
                while (!st.empty() && (tt > st.top().second))
                {
                    st.pop();
                }
                if (!st.empty())
                {
                    a[i] = i - (st.top().first);
                }
            }
            st.push(make_pair(i, tt));
        }
    }
    for(auto val : a) cout << val << " ";
    return 0;
}