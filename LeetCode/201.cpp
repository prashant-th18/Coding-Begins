class Solution {
    public:
        int rangeBitwiseAnd1(int l, int r) {
            int ans = 0, t1 = 0;
            for(int i = 0; i < 31; ++i) {
                if((l >> i) & 1) {    
                    t1 += (1 << i);
                    if(i == 30) {
                        ans += (1 << i);
                    }
                    else {
                        int t2 = (1 << (i + 1));
                        t2 -= t1;
                        if(r - l < t2) {
                            ans += (1 << i);
                        }
                    }
                }
            }
            return ans;
        }
        int rangeBitwiseAnd(int l, int r) {
            int ans = 0;
            for(int i = 30; i >= 0; --i) {
                bool f1 = (l >> i) & 1;
                bool f2 = (r >> i) & 1;
                if(f1 != f2) break;
                else if(f1 && f2) ans += (1 << i);
            }
            return ans;
        }
};
