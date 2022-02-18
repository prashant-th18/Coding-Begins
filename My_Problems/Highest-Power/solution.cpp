#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll n; cin >> n;
    int maxx = 1;
    for(ll i = 2; i < n; i++)
    {
        if(n % i == 0)
        {
            int cnt = 0;
            while(n % i == 0) n /= i, ++cnt;
            maxx = max(maxx, cnt);
        }
    }
    cout << maxx;
}

