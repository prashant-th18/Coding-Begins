using pii = pair<int, int>;
class Solution {
public:
    int carFleet(int t, vector<int>& pos, vector<int>& s) {
        int n = pos.size();
        vector<pii> v(n);
        for(int i = 0; i < n; ++i) {
            v[i] = pii(t - pos[i], s[i]);
        }
        sort(v.begin(), v.end());
        int c = 1, p, sp;
        for(int i = 0; i < n; ++i) {
            int gg = gcd(v[i].first, v[i].second);
            v[i].first /= gg, v[i].second /= gg;
            if(i == 0) {
                p = v[i].first, sp = v[i].second;
            }
            else {
                int tp = v[i].first, tsp = v[i].second;
                // tp / tsp -> time2
                // p / sp -> time1
                // if time1 >= time2 -> join
                // otherwise new ride
                // p / sp >= tp / tsp
                if(1LL * p * tsp >= 1LL * tp * sp) {
                    continue;
                }
                else {
                    ++c;
                    p = tp; sp = tsp;
                }
            }
        }
        return c;
    }
};
