// Now the modification query is to add a number to all elements in a range, and the reading query is to find the
// maximum in a range.

#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> t, lazy; // At each vertex of "t", we keep the maximum of that segment
void push(int in) {
    // push pushes the value at lazy[in] to it's children
    t[2 * in] += lazy[in];
    lazy[2 * in] += lazy[in];
    t[2 * in + 1] += lazy[in];
    lazy[2 * in + 1] += lazy[in];
    lazy[in] = 0; // Mtlb is segment pr kuch extra add ni hua
}
void update(int in, int s, int e, int qs, int qe, int addend) {
    // we want to add "addend" to a[qs .. qe]
    if(qs > qe) return;
    if(s == qs && e == qe) {
        // That means we can apply the "addend" here
        // since t[in] keeps the maximum of this segment, so after adding "addend" to every element of this segment
        // t[in](new) = t[in](old) + addend
        t[in] += addend;
        lazy[in] += addend;
        // Lazy[in] keeps the value that needs to be passed to it's children whenever necesary
    }
    else {
        push(in);
        int mid = (s + e) / 2;
        update(2 * in, s, mid, qs, min(mid, qe), addend);
        update(2 * in + 1, mid + 1, qe, max(mid + 1, qs), qe, addend);
        t[in] = max(t[2 * in], t[2 * in + 1]);
    }
}
int query(int in, int s, int e, int qs, int qe) {
    if(qs > qe) return INT_MIN;
    if(qs <= s && e <= qe) {
        // Whole segment inside the query
        return t[in];
    }
    push(in);
    int mid = (s + e) / 2;
    return max(query(2 * in, s, mid, qs, min(mid, qe)), query(2 * in + 1, mid + 1, e, max(mid + 1, qs), qe));
}
int main() {
    cin >> n;
    // We are assuming that all the values of the vector on which we are working are 0
    t.assign(4 * n, 0);
    lazy.assign(4 * n, 0);
    update(1, 0, n - 1, 0, 2, 3);
    update(1, 0, n - 1, 1, 3, 2);
    cout << query(1, 0, n - 1, 2, 4);
    return 0;
}
