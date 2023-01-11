#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 15;
const long double PRECISION = 1e-3, INF = 1e18;

long double dp[1 << MAX_N][MAX_N], p[MAX_N];  // p[i] = pow(speed_red, i)

struct Mouse {
	long double x, y, time;
};

long double dist(Mouse a, Mouse b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int mice_num;
long double speed_red;
vector<Mouse> mice;
Mouse orig{0, 0, 0};

bool check(long double v) {
	for (auto &i : dp) {
		for (long double &j : i) {
			j = INF;
		}
	}

	for (int i = 0; i < mice_num; ++i) {
		long double time = dist(orig, mice[i]) / v;
		if (time <= mice[i].time) {
			dp[1 << i][i] = time;
		}
	}

	for (int mask = 1; mask < (1 << mice_num); mask++) {
		int num_mice = __builtin_popcount(mask) - 1;
		for (int i = 0; i < mice_num; ++i) {
			if (mask & (1 << i)) {
				int pre = mask ^ (1 << i);
				for (int j = 0; j < mice_num; ++j) {
					if (pre & (1 << j)) {
						long double cur_v = v * p[num_mice];
						long double time = dp[pre][j] + dist(mice[j], mice[i]) / cur_v;
						if (dp[pre][j] != INF && time <= mice[i].time) {
							dp[mask][i] = min(dp[mask][i], time);
						}
					}
				}
			}
		}
	}

	for (int i = 0; i < mice_num; ++i) {
		if (dp[(1 << mice_num) - 1][i] != INF) {
			return true;
		}
	}
	return false;
}

int main() {
	cin >> mice_num;
	mice.resize(mice_num);
	for (int i = 0; i < mice_num; ++i) {
		cin >> mice[i].x >> mice[i].y >> mice[i].time;
	}
	
	cin >> speed_red;
	p[0] = 1;
	for (int i = 1; i < MAX_N; ++i) {
		p[i] = p[i - 1] * speed_red;
	}

	long double l = 0, r = 1e9;
	while (r - l > PRECISION) {
		long double mid = (l + r) / 2;
		if (check(mid)) {
			r = mid;
		} else {
			l = mid;
		}
	}
	cout << fixed << setprecision(16) << l << "\n";
}
