class Solution {
public:
	int dx[4] = {-1, 0, 1, 0};
	int dy[4] = {0, 1, 0, -1};
	vector<vector<bool>> vis;
	void fun(vector<vector<int>>& v, int sr, int sc, int col, int c) {
		vis[sr][sc] = true;
		cout << sr << ' ' << sc << endl;
		v[sr][sc] = c;
		for(int i = 0; i < 4; ++i) {
			int ni = sr + dx[i], nj = sc + dy[i];
			if(ni >= 0 && ni < v.size() && nj >= 0 && nj < v[0].size() && v[ni][nj] == col && !vis[ni][nj]) {
				fun(v, ni, nj, col, c);
			}
		}
	}
    vector<vector<int>> floodFill(vector<vector<int>>& v, int sr, int sc, int c) {
		vis.assign(v.size(), vector<bool>(v[0].size(), false));
        fun(v, sr, sc, v[sr][sc], c);
		return v;
    }
};
