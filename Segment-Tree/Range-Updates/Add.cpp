// You are given an array [0 .. n - 1]
// You will be given queries -> (l, r, x) 
// -> From index "l" to "r", add "x"
// And also get(i), i.e. get the value of index "i"
//
// In this problem, at each node of the tree, we keep that what is the common value that is added to all the 
// elements of this range [l .. r]

#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> v, t;
void build(int in = 1, int s = 0, int e = n - 1) {
    if(s == e) {
        t[in] = v[s];
    }
    else {
        int mid = (s + e) / 2;
        build(2 * in, s, mid);
        build(2 * in + 1, mid + 1, e);
        t[in] = 0; // t[in] tells the common value added to all the elements present in the range [l .. r]
    }
}
void update(int in, int s, int e, int qs, int qe, int add) {
    if(qs > qe) return;
    if(s == qs && e == qe) {
        // Since this node has segment that is fully inside the query, so that means all the elements of this range
        // i.e. a[s .. e] are increased by "add"
        t[in] += add; // So updating the whole segment
    }
    else {
        int mid = (s + e) / 2;
        update(2 * in, s, mid, qs, min(qe, mid), add);
        update(2 * in + 1, mid + 1, e, max(mid + 1, qs), qe, add);
    }
}
int get(int in, int s, int e, int pos) { // gets the value at a[pos]
    if(s == e) return t[in];
    else {
        int mid = (s + e) / 2;
        if(pos <= mid) {
            return t[in] + get(2 * in, s, mid, pos);
            // Two things are added
            // 1. The value at this whole segment
            // 2. The value which we get from the left child
        }
        else {
            return t[in] + get(2 * in + 1, mid + 1, e, pos);
        }
    }
}
int main() {
    cin >> n;
    v.assign(n, 0);
    t.assign(4 * n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    build();
    update(1, 0, n - 1, 2, 3, 4);
    cout << get(1, 0, n - 1, 3);
    return 0;
}
