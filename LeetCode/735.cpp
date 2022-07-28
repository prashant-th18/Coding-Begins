#define sz(x) ((int)x.size())
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        vector<int> s;
        for(int i = 0; i < a.size(); ++i) {
            if(a[i] > 0) s.push_back(a[i]);
            else {
                a[i] = -a[i];
                bool flag = false;
                while(sz(s) > 0 && s.back() > 0) {
                    if(s.back() < a[i]) s.pop_back();
                    else if(s.back() == a[i]) {
                        s.pop_back();
                        flag = true;
                        break;
                    }
                    else break;
                }
                if(flag == false) {
                    if(sz(s) == 0 || s.back() < 0) s.push_back(-a[i]);
                }
            }
        }
        return s;
    }
};
