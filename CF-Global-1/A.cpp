#include<bits/stdc++.h>
using namespace std;
int main()
{
    int b, k; cin >> b >> k;
    int odd = 0;
    vector<int> v(k);
    for (int &val : v) {
        cin >> val;
    }
    for(int i = k - 1; i >= 0; --i)
    {
        if(i == k - 1)
        {
            odd += (v[i] & 1);
        }
        else
        {
            odd += ((v[i] & 1) && (b & 1));
        }
    }
    cout << ((odd & 1) ? ("odd") : ("even"));
    return 0;
}
