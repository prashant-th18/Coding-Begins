#define all(x) begin(x), end(x)
#define sz(x) ((int)x.size())
class Solution {
public:
    const double PI = M_PI;
    int visiblePoints(vector<vector<int>>& p, int a, vector<int>& l) {
        int c = 0;
        vector<double> v;
        for (int i = 0; i < p.size(); i++) {
            int dx = abs(l[0] - p[i][0]);
            int dy = abs(l[1] - p[i][1]);
            if(dy == dx && dx == 0) {
                ++c;
                continue;
            }
            if(dx == 0) {
                if(p[i][1] > l[1]) {
                    v.push_back((double)0);
                }
                else {
                    if(l[1] > p[i][1]) {
                        v.push_back((double)180);
                    }
                }
            }
            else if(dy == 0) {
                if(l[0] < p[i][0]) v.push_back((double)90);
                else v.push_back((double)270);
            }
            else {
                int gg = gcd(dy, dx);
                dy /= gg; dx /= gg;
                // Both non zero
                double result = atan((double)dy / dx) * 180 / PI;
                if(p[i][0] > l[0] && p[i][1] > l[1]) {
                    v.push_back(result);
                }
                else if(p[i][0] > l[0] && p[i][1] < l[1]) {
                    v.push_back(90 + result);
                }
                else if(p[i][0] < l[0] && p[i][1] < l[1]) {
                    v.push_back(180 + result);
                }
                else v.push_back(270 + result);
            }
        }
        int maxx = 0;
        sort(v.begin(), v.end());
        auto get = [&](int i, int angle) {
              int s = i, e = sz(v) - 1, ans = -1;
              while(s <= e) {
                  int mid = (s + e) / 2;
                  if(v[mid] - v[i] <= (double)angle) {
                      ans = mid;
                      s = mid + 1;
                  }
                  else e = mid - 1;
              }
              return ans;
        };
        for(int i = 0; i < v.size(); ++i) {
            double angle = v[i] + a;
            if(angle >= 360) {
                angle -= 360;
                int it = get(0, angle);
                maxx = max(maxx, (int)(it + 1 + (sz(v) - i)));
            }
            else {
                int it = get(i, angle);
                maxx = max(maxx, (int)(it + 1 - i));
            }
        }
        return c + maxx;
    }
};
