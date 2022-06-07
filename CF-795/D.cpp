#ifdef LOCAL
    #define _GLIBCXX_DEBUG
#endif
// #pragma GCC optimize("O3")
// #pragma GCC target("popcnt")
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
const int MOD = 1000000007;
typedef long long ll;
typedef long double ld;
#define sz(s) ((int)s.size())
#define all(v) begin(v), end(v)
#define ff first
#define ss second

// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

// #define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> /* Ordered Set */
// #define ordered_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> /* Ordered MultiSet */


// https://www.geeksforgeeks.org/iterative-segment-tree-range-maximum-query-with-node-update/
// iterative segment tree.
void construct_segment_tree(vector<int>& segtree,
							vector<int>& a, int n)
{
	// assign values to leaves of the segment tree
	for (int i = 0; i < n; i++)
		segtree[n + i] = a[i];

	/* assign values to internal nodes
	to compute maximum in a given range */
	for (int i = n - 1; i >= 1; i--)
		segtree[i] = max(segtree[2 * i],
						segtree[2 * i + 1]);
}

void update(vector<int>& segtree, int pos, int value,
			int n)
{
	// change the index to leaf node first
	pos += n;

	// update the value at the leaf node
	// at the exact index
	segtree[pos] = value;

	while (pos > 1) {

		// move up one level at a time in the tree
		pos >>= 1;

		// update the values in the nodes in
		// the next higher level
		segtree[pos] = max(segtree[2 * pos],
						segtree[2 * pos + 1]);
	}
}

int range_query(vector<int>& segtree, int left, int
													right,
				int n)
{
	/* Basically the left and right indices will move
		towards right and left respectively and with
		every each next higher level and compute the
		maximum at each height. */
	// change the index to leaf node first
	left += n;
	right += n;

	// initialize maximum to a very low value
	int ma = INT_MIN;

	while (left < right) {

		// if left index in odd
		if (left & 1) {
			ma = max(ma, segtree[left]);

			// make left index even
			left++;
		}

		// if right index in odd
		if (right & 1) {

			// make right index even
			right--;

			ma = max(ma, segtree[right]);
		}

		// move to the next higher level
		left /= 2;
		right /= 2;
	}
	return ma;
}

// *-> KISS*
int solve() {
    int n; cin >> n;
    vector<int> v(n);
    set<int> pos, neg;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if(v[i] < 0) neg.insert(i);
        else if(v[i] > 0) pos.insert(i);
    }
    vector<int> segtree(2 * n);
    construct_segment_tree(segtree, v, n);
    vector<ll> pre(n, 0);
    pre[0] = v[0];
    for(int i = 1; i < n; ++i) pre[i] = pre[i - 1] + v[i];
    ll maxi = LLONG_MIN, ind = n - 1;
    vector<ll> maxx(n, 0);
    for(int i = n - 1; i >= 0; --i) {
        maxx[i] = ind;
        if(pre[i] >= maxi) {
            maxi = pre[i];
            ind = i;
        }
    }
    auto check = [&](int in) {
        if(in == n - 1) return false;
        if(v[in] > 0) {
            auto p = pos.upper_bound(in);
            auto nn = neg.upper_bound(in);
            if(nn == neg.end()) return true;
            if(p == pos.end()) return false;
            if(*p < *nn) return true;
        }
        return false;
    };
    for(int i = 0; i < n; ++i) {
        int si = i, ei = maxx[i];
        ll sum = ((i == 0) ? (pre[ei]) : (pre[ei] - pre[i - 1]));
        if(range_query(segtree, si, ei + 1, n) < sum || check(i)) {
            cout << "No"; return 0;
        }
    }
    cout << "Yes";
    return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TET = 1;
    cin >> TET;
    cout << fixed << setprecision(6);
    for (int i = 1; i <= TET; i++) {
#ifdef LOCAL
        cout << "##################" << '\n';
#endif
        if (solve())
        {
            break;
        }
        cout << '\n';
    }
#ifdef LOCAL
    cout << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif
    return 0;
}
// -> Keep It Simple Stupid!
