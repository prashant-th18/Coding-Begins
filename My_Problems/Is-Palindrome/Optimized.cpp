#include "bits/stdc++.h"
using namespace std;

int n;
string s;
vector<int> t[26], lazy[26];
vector<bool> visited[26];
void build(vector<int>& seg, int order, int in, int si, int ei) {
	if(si == ei) {
		seg[in] = ((s[si] - 'a') == order);
	}
	else {
		int mid = (si + ei) >> 1;
		build(seg, order, 2 * in, si, mid);
		build(seg, order, 2 * in + 1, mid + 1, ei);
		seg[in] = seg[2 * in] + seg[2 * in + 1];
	}
}
void push(vector<int>& seg, vector<int>& laz, vector<bool>& vis, 
						int in, int si, int ei) {
	if(vis[in]) {
		int mid = (si + ei) >> 1;
		seg[2 * in] = (mid - si + 1) * laz[in];
		seg[2 * in + 1] = (ei - mid) * laz[in];
		laz[2 * in] = laz[2 * in + 1] = laz[in];
		laz[in] = 0;
		vis[in] = false;
		vis[2 * in] = vis[2 * in + 1] = true;
	}
}
void update(vector<int>& seg, vector<int>&laz, vector<bool>& vis, 
					int in, int si, int ei, int qs, int qe, int nval) {
	if(qs > qe) return;
	if(si == qs && ei == qe) {
		seg[in] = (ei - si + 1) * nval;
		laz[in] = nval;
		vis[in] = true;
	}
	else {
		int mid = (si + ei) >> 1;
		push(seg, laz, vis, in, si, ei);
		update(seg, laz, vis, 2 * in, si, mid, qs, min(mid, qe), nval);
		update(seg, laz, vis, 2 * in + 1, mid + 1, ei, max(mid + 1, qs), qe, nval);
		seg[in] = seg[2 * in] + seg[2 * in + 1];		
	}
}
int query(vector<int>& seg, vector<int>& laz, vector<bool>& vis, 
					int in, int si, int ei, int qs, int qe) {
	if(qs > qe) return 0;
	if(si == qs && ei == qe) return seg[in];
	
	int mid = (si + ei) >> 1;
	push(seg, laz, vis, in, si, ei);
	return query(seg, laz, vis, 2 * in, si, mid, qs, min(mid, qe)) + 
			query(seg, laz, vis, 2 * in + 1, mid + 1, ei, max(qs, mid + 1), qe);	
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> s;
	n = s.size();
	assert(1 <= n && n <= (int)1e5);
	
	for(int i = 0; i < 26; ++i) {
		t[i].assign(4 * n, 0);
		lazy[i].assign(4 * n, 0);
		visited[i].assign(4 * n, false);
	}
	
	for(int i = 0; i < 26; ++i) {
		build(t[i], i, 1, 0, n - 1);
	}
	
	int q; cin >> q;
	assert(1 <= q && q <= (int)1e5);
	while(q--) {
		int type; cin >> type;
		assert(type == 1 || type == 2);
		if(type == 1) {
			int l, r; cin >> l >> r;
			assert(1 <= l && l <= r && r <= n);
			char ch; cin >> ch;
			assert('a' <= ch && ch <= 'z');
			--l, --r;
			for(int i = 0; i < 26; ++i) {
				update(t[i], lazy[i], visited[i], 1, 0, n - 1, l, r, ((ch - 'a') == i));
			}
		}
		else {
			int l, r; cin >> l >> r;
			assert(1 <= l && l <= r && r <= n);
			--l, --r;
			// We can make it palindrome
			// If the number of characters whose frequency in this range
			// is odd <= 1
			int odd = 0;
			for(int i = 0; i < 26; ++i) {
				if(query(t[i], lazy[i], visited[i], 1, 0, n - 1, l, r) & 1) ++odd;
			}
			if(odd <= 1) cout << "Yes\n";
			else cout << "No\n";
		}
	}
	return 0;
}

