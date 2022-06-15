class Solution {
public:
    vector<int> findOriginalArray(vector<int>& v) {
        vector<int> ans;
        vector<int> cnt(100001, 0);
        for(const auto& val : v) cnt[val]++;
        sort(v.begin(), v.end());
        for(int i = v.size() - 1; i >= 0; --i) {
            if(cnt[v[i]] == 0) continue;
            if(v[i] % 2 == 1) return vector<int>(0);
            --cnt[v[i]];
            int l = v[i] / 2;
            if(cnt[l] == 0) return vector<int>(0);
            --cnt[l];
            ans.push_back(l);
        }
        return ans;
    }
};
