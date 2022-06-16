#include<bits/stdc++.h>
using namespace std;
void insertAtBottom(stack<int> & st, int temp)
{
    if (st.empty())
    {
        st.push(temp);
        return;
    }
    int tt = st.top();
    st.pop();
    insertAtBottom(st, temp);
    st.push(tt);
}
void reverseStackRec(stack<int> & st)
{
    if (st.empty())
    {
        return;
    }
    int temp = st.top();
    st.pop();
    reverseStackRec(st);
    insertAtBottom(st, temp);
}
int main()
{
    int n;
    cin >> n;
    stack<int> st;
    while(n--)
    {
        int tt;
        cin >> tt;
        st.push(tt);
    }
    n = st.size();
    reverseStackRec(st);
    while(n--)
    {
        cout << st.top() << "\n";
        st.pop();
    }
    return 0;
}