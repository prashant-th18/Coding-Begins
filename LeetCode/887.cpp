class Solution {
	public:
		int superEggDrop(int k, int n) {
			int ans = -1;
			for(int i = 0; i <= n; ++i) {
				// Assume Egg is at position "i"
				int s = 1, e = n;
				int t = k;
				int op = 0;
				while(s < e && t != 1) {
					int mid = (s + e) >> 1;
					if(i < mid) {
						// Egg will surely break
						e = mid - 1;
						--t;
					}
					else {
						/* pre = mid; */
						s = mid + 1;
					}
					++op;
				}
				if(i == 0) {
					ans = max(ans, op + 1);
					continue;
				}
				if(s == e) ans = max(ans, op + 1);
				else {
					if((e != n) && (i == e || i == e - 1)) {
						ans = max(ans, op + e - s);
					}
					else if(i == e) {
						ans = max(ans, op + n - s);
					}
					else {
						ans = max(ans, op + i - s + 2);
					}
				}
				cout << i << ' ' << ans << endl;
			}
			return ans;
		}
};
