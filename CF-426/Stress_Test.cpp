#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
string wrong(int a, int b)
{
    ll a, b; cin >> a >> b;
    for(ll i = 2; i * i <= max(a, b); ++i)
    {
        if(a % i == 0 || b % i == 0)
        {
            int cc1 = 0, cc2 = 0;
            while(a % i == 0) a /= i, ++cc1;
            while(b % i == 0) b /= i, ++cc2;
            if(cc1 == 0 || cc2 == 0) { return "NO"; }
            else
            {
                if(((cc1 + cc2) % 3 != 0) || !(max(cc1, cc2) <= 2 * min(cc1, cc2)))
                {
                    return "NO";
                }
            }
        }
    }
    if(a == 1 && b == 1)
    return "YES"; 
    return "NO";
}
string brute(int a, int b)
{
    
}
int main()
{
    while(1){
    int a = uniform_int_distribution<int>(1, 1000000000)(rng);
    int b = uniform_int_distribution<int>(1, 1000000000)(rng);
    if(brute(a, b) != wrong(a, b))
    {
        cout << a << ' ' << b << endl;
        return 0;
    }
    else cout << "Ok!\n";
    }
    return 0;
}
