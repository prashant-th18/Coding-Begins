// Compute Powers in O(log2n)
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll fast_power_compute(ll a, ll b)
{
    if(b == 0)
    {
        return 1;
    }
    ll answer = fast_power_compute(a, b / 2);
    answer *= answer;
    if (b & 1)
    {
        answer *= a;
    }
    return answer;
}
int main()
{
    cout << fast_power_compute(2, 62);
    return 0;
}