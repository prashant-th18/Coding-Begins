#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define sz(x) ((int)x.size())
#define ff first
#define ss second
#define all(x) begin(x), end(x)
const int MOD = 1e9 + 7;
// *-> KISS*

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int test = 1;
    //cin >> test;
    for(int t_ = 0; t_ < test; t_++)
    {
        ll a, b, c, d; cin >> a >> b >> c >> d;
        map<pair<int, int>, int> mp;
     auto fun = [&](int A, int B) -> void {   
        int t1 = 1, t2 = 2;
        for(int i = 0; i < 8; ++i)
        {
            if(i == 4) swap(t1, t2);
            if(i % 4 == 0) mp[pair(A - t1, B - t2)]++;
            else if(i % 4 == 1) mp[pair(A - t1, B + t2)]++;
            else if(i % 4 == 2) mp[pair(A + t1, B - t2)]++;
            else mp[pair(A + t1, B + t2)]++;
        }
    };
     fun(a, b); fun(c, d);
     for(auto val : mp)
     {
         if(val.ss >= 2)  { cout << "Yes"; return 0; }
     }
     cout << "No";
        cout << '\n';	
    }
    return 0;
}
// -> Keep It Simple Stupid!
