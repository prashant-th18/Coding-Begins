#include"bits/stdc++.h"
using namespace std;
#define all(x) begin(x), end(x)
int lis(vector<int>& v) {
    // Longest Increasing Subsequence
    int n = v.size();
    vector<int> dp(n, 1);
    for(int i = 0; i < n; ++i) {
        for(int j = i - 1; j >= 0; --j) {
            if(v[j] < v[i]) {
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
    }
    return *max_element(all(dp));
}
vector<int> rlis(vector<int>& v) {
    // Finding the subsequence with maximum LIS
    int n = v.size();
    vector<int> dp(n, 1), par(n, -1);
    // dp[i] -> Length of longest Increasing Subsequence ending at index "i"
    // par[i] -> if dp[i] > 1, then par[i] will tell the index using which dp[i] became i.e ->
    // dp[i] = 1 + dp[j] (For some "j")
    // So, par[i] will tell index "j"
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < i; ++j) {
            if(v[j] < v[i] && dp[i] < 1 + dp[j]) {
                dp[i] = 1 + dp[j];
                par[i] = j;
            }
        }
    }
    int ans = dp[0], ind = 0;
    for(int i = 0; i < n; ++i) {
        if(dp[i] > ans) {
            ans = dp[i];
            ind = i;
        }
    }
    vector<int> sub;
    while(ind != -1) {
        sub.push_back(ind);
        ind = par[ind];
    }
    reverse(all(sub));
    return sub;
}
int lisFast(vector<int>& a) {
    int n = a.size();
    const int INF = 1e9;
    vector<int> dp(n + 1, INF);
    // dp[i] -> will be the element at which a subsequence of length "i" terminates. 
    // If there are multiple such sequences, then we take the one that ends in the smallest element.
    dp[0] = -INF;
    for(int i = 0; i < n; ++i) {
        // We will use binary search
        int j = upper_bound(all(dp), a[i]) - begin(dp);
        if(dp[j - 1] < a[i] && a[i] < dp[j]) {
            dp[j] = a[i];
        }
    }
    int ans = 0; // Length of Longest Increasing Subsequence
    for(int i = 0; i <= n; ++i) {
        if(dp[i] < INF) ans = i;
    }
    return ans;
}
int main() {
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cout << lis(v) << ' ' << lisFast(v) << endl;
    auto t = rlis(v);
    for(auto& val : t) cout << val << ' ';
    return 0;
}
