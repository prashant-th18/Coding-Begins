#include<bits/stdc++.h>
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
class Solution {
public:
    int sum = 0;
    vector<int> pre;
    Solution(vector<int>& w) {
        sum += w[0];
        pre.push_back(w[0]);
        for (int i = 1; i < w.size(); i++) {
            pre.push_back(pre.back() + w[i]);
            sum += w[i];
        }
    }
    
    int pickIndex() {
        // int num = uniform_int_distribution<int>(0, sum)(rng);
        int num = rand() % (sum) + 1;
        auto it = lower_bound(begin(pre), end(pre), num) - begin(pre);
        return it;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
