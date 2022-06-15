class Solution {
public:
    vector<int> cnt, wi;
    int i, c = 0;
    Solution(vector<int>& w) {
        cnt = w;
        wi = w;
        i = 0;
    }
    
    int pickIndex() {
        if(c == cnt.size()) {
            cnt = wi;
            c = 0;
        }
        while(cnt[i] == 0) {
            i = (i + 1) % cnt.size();
        }
        cnt[i]--;
        if(cnt[i] == 0) ++c;
        int ind = i;
        i = (i + 1) % cnt.size();
        return ind;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
