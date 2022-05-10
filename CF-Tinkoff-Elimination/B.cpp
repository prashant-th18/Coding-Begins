#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef LOCAL
    void debug_print(string s) {
        cerr << "\"" << s << "\"";
    }

    void debug_print(const char* s) {
        debug_print((string)s);
    }

    void debug_print(bool val) {
        cerr << (val ? "true" : "false");
    }

    void debug_print(int val) {
        cerr << val;
    }

    void debug_print(ll val) {
        cerr << val;
    }

    void debug_print(double val) {
        cerr << val;
    }

    template<typename F, typename S>
    void debug_print(pair<F, S> val) {
        cerr << "(";
        debug_print(val.first);
        cerr << ", ";
        debug_print(val.second);
        cerr << ")";
    }

    void debug_print(vector<bool> val) {
        cerr << "{";
        bool first = true;
        for (bool x : val) {
            if (!first) {
                cerr << ", ";
            } else {
                first = false;
            }
            debug_print(x);
        }
        cerr << "}";
    }

    template<typename T>
    void debug_print(T val) {
        cerr << "{";
        bool first = true;
        for (const auto &x : val) {
            if (!first) {
                cerr << ", ";
            } else {
                first = false;
            }
            debug_print(x);
        }
        cerr << "}";
    }

    void debug_print_collection() {
        cerr << endl;
    }

    template<typename First, typename... Args>
    void debug_print_collection(First val, Args... args) {
        cerr << " ";
        debug_print(val);
        debug_print_collection(args...);
    }

#define debug(...) cerr << "@@@ " << #__VA_ARGS__ << " ="; debug_print_collection(__VA_ARGS__);

#else
    #define debug(...) 
#endif

int n, m, si, sj;
vector<string> v;
vector<vector<vector<bool>>> vis;
vector<vector<int>> turns;
bool isValid(int i, int j, int k) {
    if(i < 0 || i >= n || j < 0 || j >= m || v[i][j] == '*') return false;
    return true;
}
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int main() {
    cin >> n >> m;
    v.assign(n, "");
    vis.assign(n, vector<vector<bool>>(m, vector<bool>(4, false)));
    turns.assign(n, vector<int>(m, 0));
    for(int i = 0; i < n; ++i) {
        cin >> v[i];
        if(v[i].find('S') != -1) {
            si = i, sj = v[i].find('S');
        }
    }
    // 0 UP, 1 RIGHT, 2 DOWN, 3 LEFT
    queue<array<int, 3>> q;
    for(int i = 0; i < 4; ++i) {
        int ni = si + dx[i], nj = sj + dy[i];
        if(isValid(ni, nj, i)) q.push({ni, nj, i});
    }
    while(!q.empty()) {
        array<int, 3> temp = q.front(); q.pop();
        debug(temp);
        if(v[temp[0]][temp[1]] == 'T') {
            cout << "YES"; return 0;
        }
        for(int i = 0; i < 4; ++i) {
            int ni = temp[0] + dx[i], nj = temp[1] + dy[i];
            if(isValid(ni, nj, i)) {
                int pi = temp[0], pj = temp[1], extra = (temp[2] != i);
                if(vis[ni][nj][i]) {
                    if(extra + turns[pi][pj] <= turns[ni][nj]) {
                        turns[ni][nj] = extra + turns[pi][pj];
                        q.push({ni, nj, i});
                    }    
                }
                else if(extra + turns[temp[0]][temp[1]] <= 2) {
                    vis[ni][nj][i] = true;
                    turns[ni][nj] = extra + turns[temp[0]][temp[1]];
                    q.push({ni, nj, i});
                }
            }
        }
    }
    cout << "NO";
    return 0;
}
