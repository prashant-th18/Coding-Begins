class Solution {
public:
    vector<int> fullBloomFlowersSlow(vector<vector<int>>& flowers, vector<int>& persons) {
        vector<vector<int>> ans;
        for(int i = 0; i < flowers.size(); ++i) {
            vector<int> t1 = {flowers[i][0], -1};
            vector<int> t2 = {flowers[i][1], 1};
            ans.emplace_back(t1); ans.emplace_back(t2);
        }
        for(int i = 0; i < persons.size(); ++i) {
            vector<int> t = {persons[i], 0, i};
            ans.emplace_back(t);
        }
        sort(begin(ans), end(ans), [&](vector<int>& a, vector<int>& b) {
            return a < b; 
        });
        int cnt = 0;
        vector<int> out(persons.size());
        for(int i = 0; i < ans.size(); ++i) {
            if(ans[i][1] == -1) {
                ++cnt;
            }
            else if(ans[i][1] == 0) {
                out[ans[i][2]] = cnt;
            }
            else {
                --cnt;
            }
        }
        return out;
    }
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        vector<int> start, end;
        for(int i = 0; i < flowers.size(); ++i) {
            start.emplace_back(flowers[i][0]);
            end.emplace_back(flowers[i][1]);
        }
        sort(begin(start), start.end());
        sort(begin(end), end.end());
        vector<int> res;
        for(int &p : persons) {
            int st = upper_bound(begin(start), start.end(), p) - begin(start);
            int en = lower_bound(begin(end), end.end(), p) - begin(end);
            res.emplace_back(st - en);
        }
        return res;
    }
};
