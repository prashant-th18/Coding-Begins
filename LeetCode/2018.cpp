class Solution {
public:
    bool placeWordInCrossword(vector<vector<char>>& v, string s) {
        int m = v.size(), n = v[0].size();
        int how = s.size();
        for(int j = 0; j < n; ++j) {
            int i = 0;
            while(i < m) {
                if(v[i][j] == '#') ++i;
                else {
                    int k = i;
                    while(k < m && v[k][j] != '#') ++k;
                    if(k - i == how && ((k == m) || (v[k][j] == '#'))) {
                        int t = i;
                        while(t < k && ((v[t][j] == ' ') || (s[t - i] == v[t][j]))) ++t;
                        cout << k << ' ' << t << endl;
                        if(t == k) return true;
                        t = k - 1;
                        while(t >= i && ((v[t][j] == ' ') || (s[k - 1 - t] == v[t][j]))) --t;
                        if(t == i - 1) return true;
                    }
                    i = k;
                }
            }
        }
        for(int i = 0; i < m; ++i) {
            int j = 0;
            while(j < n) {
                if(v[i][j] == '#') ++j;
                else {
                    int k = j;
                    while(k < n && v[i][k] != '#') ++k;
                    if(k - j == how && ((k == n) || (v[i][k] == '#'))) {
                        int t = j;
                        while(t < k && ((v[i][t] == ' ') || (s[t - j] == v[i][t]))) ++t;
                        if(t == k) return true;
                        t = k - 1;
                        while(t >= j && ((v[i][t] == ' ') || (s[k - 1 - t] == v[i][t]))) --t;
                        if(t == j - 1) return true;
                    }
                    j = k;
                }
            }
        }
        return false;
    }
};
