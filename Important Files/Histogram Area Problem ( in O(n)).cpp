// Histogram Area Problem
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, area = 0;
    cin >> n;
    int a[n + 1] {};
    for (int i = 0 ; i < n; ++i) cin >> a[i];
    stack<int> st;
    for (int i = 0; i <= n; ++i)
    {
        if (st.empty())
        {
            st.push(i);
        }
        else
        {
            if (a[i] >= a[st.top()])
            {
                st.push(i);
            }
            else
            {
                while (!st.empty() && a[st.top()] > a[i])
                {
                    int temp = a[st.top()];
                    st.pop();
                    if (st.empty())
                    {
                        area = max(area, temp * (i));
                    }
                    else
                    {
                        area = max(area, temp * (i - st.top() - 1));
                    }
                }
                st.push(i);
            }
        }
    }
    cout << area;
    return 0;
}