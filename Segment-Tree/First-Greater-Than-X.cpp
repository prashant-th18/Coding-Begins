// In a range from [l, r], find smallest index "i", such that v[i] > x
// So, we keep maximum of the segments in the segment tree, and then we check, that if the left child's maximum
// is greater than 'x', then we go to left child otherwise right child

#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> v, t;
void build(int in = 1, int s = 0, int e = n - 1) {
    if(s == e) t[in] = v[s];
    else {
        int mid = (s + e) / 2;
        build(2 * in, s, mid);
        build(2 * in + 1, mid + 1, e);
        t[in] = max(t[2 * in], t[2 * in + 1]);
    }
}
void update(int in, int s, int e, int pos, int nval) {
    if(s == e) {
        v[pos] = nval;
        t[in] = nval;
    }
    else {
        int mid = (s + e) / 2;
        if(pos <= mid) update(2 * in, s, mid, pos, nval);
        else update(2 * in + 1, mid + 1, e, pos, nval);
        t[in] = max(t[2 * in], t[2 * in + 1]);
    }
}
int get_first(int in, int s, int e, int qs, int qe, int x) {
    // Check whether there is some overlapping in the [qs, qe] and [s, e]
    if(qe < s || qs > e) return -1;
    if(qs <= s && e <= qe) {
        // Check if the maximum of this segment is greater than x
        if(t[in] <= x) return -1; // Not Found
        int ans = -1;
        while(s <= e) {
            int mid = (s + e) / 2;
            if(t[2 * in] > x) {
                ans = mid; // That is, maximum is present in the left segment
                e = mid;
                in = 2 * in;
            }
            else {
                in = 2 * in + 1;
                s = mid + 1;
            }
        }
        return ans;
    }
    int mid = (s + e) / 2;
    int rs = get_first(2 * in, s, mid, qs, qe, x);
    if(rs != -1) {
        // This means I have found a number greater than 'x' in the left segment
        return rs;
    }
    return get_first(2 * in + 1, mid + 1, e, qs, qe, x);
}
int main() {
    cin >> n;
    v.assign(n, 0);
    t.assign(4 * n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    build();
    cout << get_first(1, 0, n - 1, 0, n - 1, 4) << endl;
    update(1, 0, n - 1, 2, 4);
    cout << get_first(1, 0, n - 1, 0, n - 1, 3);
    return 0;
}
