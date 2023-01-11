#define all(x) x.begin(), x.end()
#include<algorithm>
class Solution {
public:
    int minEatingSpeed(vector<int>& v, int h) {
        int s = 1, e = *max_element(all(v));
        int ans = 0;
        while(s <= e) {
            int mid = (s + e) >> 1;
            long long c = 0;
            for(int i = 0; i < v.size(); ++i) {
                c += (v[i] + mid - 1) / mid;
            }
            if(c <= h) {
                ans = mid;
                e = mid - 1;
            }
            else {
                s = mid + 1;
            }
        }
        return ans;
    }
};
