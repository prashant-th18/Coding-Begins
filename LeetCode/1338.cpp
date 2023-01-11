#define sz(x) ((int)x.size())
#define ss second
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> mp;
        for (int i = 0; i < sz(arr); i++) {
            mp[arr[i]]++;
        }
        vector<int> v;
        for(auto& val : mp) v.push_back(val.ss);
        sort(v.begin(), v.end(), greater<int>());
        int c = 0, sum = 0;
        for(int i = 0; i < sz(v) && sum < sz(arr) / 2; ++i) {
            ++c;
            sum += v[i];
        }
        return c;
    }
};
