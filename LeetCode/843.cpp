/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
#include<bits/stdc++.h>
using namespace std;
#define sz(x) ((int)x.size())
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
class Solution {
public:
    int getRandom(int e) {
        return uniform_int_distribution<int>(0, e)(rng);
    }
    void findSecretWord(vector<string>& w, Master& master) {
        int c = 0;
        while(c < 10) {
            ++c;
            int get = getRandom(sz(w) - 1);
            int num = master.guess(w[get]);
            if(num == -1) continue;
            else {
                vector<string> t;
                for(int i = 0; i < sz(w); ++i) {
                    int cnt = 0;
                    for(int j = 0; j < 6; ++j) {
                        cnt += (w[get][j] == w[i][j]);
                    }
                    if(cnt == num) t.push_back(w[i]);
                }
                w = t;
            }
        }
    }
};
