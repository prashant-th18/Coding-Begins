#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        map<int, vector<int>> x, y;
        for(auto& val : points) {
           x[val[0]].push_back(val[1]);
           y[val[1]].push_back(val[0]);
        }
        for(auto& val : x) {
            sort(val.ss.begin(), val.ss.end());
        }
        int area = INT_MAX;
        for(auto& val : y) sort(val.ss.begin(), val.ss.end());
        for(auto& val : x) {
            auto& v = val.ss;
            for(int i = 0; i < v.size(); ++i) {
                vector<int>& down = y[v[i]];
                int in = upper_bound(all(down), val.first) - begin(down);
                if(in == sz(down)) continue;
                for(int j = i + 1; j < v.size(); ++j) {
                    int in2 = in;
                    vector<int>& up = y[v[j]];
                    int in1 = upper_bound(all(up), val.first) - begin(up);
                    while(in1 < sz(up) && in2 < sz(down)) {
                        if(up[in1] == down[in2]) {
                            area = min(area, (v[j] - v[i]) * (down[in2] - val.ff));
                            break;
                        }
                        else if(up[in1] < down[in2]) ++in1;
                        else ++in2;
                    }
                }
            }
        }
        if(area == INT_MAX) area = 0;
        return area;
    }
};
