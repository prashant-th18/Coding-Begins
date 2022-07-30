class Solution {
public:
    bool isRobotBounded(string s) {
        int x = 0, y = 0;
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        int k = 1;
        for(int i = 0; i < 4; ++i) {
            for(int j = 0; j < s.size(); ++j) {
                if(s[j] == 'G') {
                    x += dx[k];
                    y += dy[k];
                }
                else if(s[j] == 'L') {
                    k = (k - 1 + 4) % 4;
                }
                else {
                    k = (k + 1) % 4;
                }
            }
            if(x == 0 && y == 0) return true;
        }
        return false;
    }
};
