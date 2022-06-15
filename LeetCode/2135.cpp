#include<bits/stdc++.h>
#define sz(x) (int)x.size()
class Solution {
public:
    int wordCountSlow(vector<string>& sw, vector<string>& tw) {
        set<vector<int>> st;
        for(auto& val : sw) {
            vector<int> v(26, 0);
            for(auto& vall : val) {
                v[vall - 'a']++;
            }
            st.insert(v);
        }
        int ans = 0;
        for(const auto& val : tw) {
            vector<int> cnt(26, 0);
            for(const auto& vall : val) {
                cnt[vall - 'a']++;
            }
            for(int i = 0; i < 26; ++i) {
                if(cnt[i] == 1) {
                    --cnt[i];
                    if(st.count(cnt)) {
                        ++ans;
                        break;
                    }
                    ++cnt[i];
                }
            }
        }
        return ans;
    }
    // Below is much faster
    int wordCount(vector<string> &sw, vector<string>& tw) {
        // bit-masking
        // Only works when -> No letter occurs more than once in any string of startWords or targetWords.
        set<int> st;
        for(auto& val : sw) {
            int hash = 0;
            for(const auto& vall : val) {
                hash += ((1 << (vall - 'a')));
            }
            st.insert(hash);
        }
        int ans {};
        for(auto& val : tw) {
            for(int i = 0; i < sz(val); ++i) {
                int h = 0;
                for(int j = 0; j < sz(val); ++j) {
                    if(i != j) {
                        h += (1 << (val[j] - 'a'));
                    }
                }
                if(st.count(h)) {
                    ++ans;
                    break;
                }
            }
        }
        return ans;
    }
};
