#include<bits/stdc++.h>
class Solution {
public:
    int longestStrChainn(vector<string>& words) {
        sort(words.begin(), words.end(), [&](string& a, string& b) {
            return a.size() < b.size(); 
        });
        int n = words.size();
        vector<int> dp(n, 1);
        for(int i = 1; i < n; ++i) {
            for(int j = i - 1; j >= 0; --j) {
                int t = words[i].size() - words[j].size();
                string& s1 = words[i];
                string& s2 = words[j];
                if(t >= 2) break;
                else if(t == 1) {
                    int p1 = 0, p2 = 0;
                    int c = 0;
                    while(p1 < s1.size() && p2 < s2.size()) {
                        if(s1[p1] == s2[p2]) ++p1, ++p2;
                        else ++c, ++p1;
                    }
                    if(c <= 1) {
                        dp[i] = max(dp[i], 1 + dp[j]);
                    }
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }

    int longestStrChain(vector<string>& words) {
        unordered_map<string, int> dp;
        sort(words.begin(), words.end(), [&](string& a, string& b) {
            return a.size() < b.size(); 
        });
        int maxx = 1;
        for(const auto& s : words) {
            dp[s] = 1;
            for(int i = 0; i < s.size(); ++i) {
                string t = s.substr(0, i) + s.substr(i + 1);
                dp[s] = max(dp[s], 1 + dp[t]);
            }
            maxx = max(maxx, dp[s]);
        }
        return maxx;
    }



};


