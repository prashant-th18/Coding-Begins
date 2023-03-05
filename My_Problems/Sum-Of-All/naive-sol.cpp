#include"bits/stdc++.h"
using namespace std;
using ll = long long;
const ll MOD = (1000000007);
#define sz(s) ((int)s.size())
ll add(ll a, ll b) {
    return (a + b) % MOD;
}
ll mul(ll a, ll b) {
    return a * b % MOD;
}
ll binexp(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) {
            ans = ans * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return ans;
}
vector<ll> v;
ll sum = 0; // Required Sum
void fun(string& s, int index) {
    if(index == sz(s)) {
        if(sz(v) == sz(s)) return; // This means that we are deleting an empty-subsequence which is not allowed.
                                   // Base Case
        ll ans = 0;
        for(int i = 0; i < sz(v); ++i) {
            // v[i] at index i means that in the resulting number, v[i] digit is at "i" distance from the last
            // position (one's place) in the number
            ans = add(ans, mul(v[i], binexp(10, (sz(v) - i - 1))));
        }
        sum = add(sum, ans);
    }
    else {
        // Either, you take s[i], or you don't take it.
        // Case 1: Taking s[i]
        int num = s[index] - '0';
        v.push_back(num);
        fun(s, index + 1);

        v.pop_back();
        // Case 2: Not taking s[i]
        fun(s, index + 1);
    }
}
int main() {
    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        fun(s, 0);
        cout << sum << '\n';
        v.clear();
        sum = 0;
    }
    return 0;
}
