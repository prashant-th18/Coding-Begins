#define sz(x) ((int)x.size())
class Solution {
public:
    int findMinDifference(vector<string>& tp) {
        vector<int> minutes(sz(tp), 0);
        for (int i = 0; i < sz(tp); i++) {
            minutes[i] = 60 * (stoi(tp[i].substr(0, 2))) + stoi(tp[i].substr(3));
        }
        sort(minutes.begin(), minutes.end());
        int mini = min(minutes[sz(minutes) - 1] - minutes[0], 24 * 60 - minutes[sz(minutes) - 1] + minutes[0]);
        for(int i = 1; i < sz(minutes); ++i) {
            mini = min(mini, minutes[i] - minutes[i - 1]);
        }
        return mini;
    }
};
