// Searching for an array prefix with a given amount
// Given any array of non-negative integers, find smallest index such that sum of first i integers is equal to x
// We will code sum of a segment using SegTree, and then we will check the index whose sum == x
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
        t[in] = t[2 * in] + t[2 * in + 1];
    }
}
void update(int in, int s, int e, int pos, int nval) {
    if(s == e) {
        t[in] = nval;
    }
    else {
        int mid = (s + e) / 2;
        if(pos <= mid) {
            update(2 * in, s, mid, pos, nval);
        }
        else {
            update(2 * in + 1, mid + 1, e, pos, nval);
        }
        t[in] = t[2 * in] + t[2 * in + 1];
    }
}
int query(int in, int s, int e, int sum) {
    if(t[in] < sum) {
        // Total Sum is less than sum, therefore not possible
        return -1;
    }
    if(s == e) {
        if(t[in] == sum) return s;
        else return -1;
    }
    int mid = (s + e) / 2;
    if(t[2 * in] >= sum) {
        return query(2 * in, s, mid, sum);
    }
    else {
        return query(2 * in + 1, mid + 1, e, sum - t[2 * in]);
    }
}
int main() {
    cin >> n;
    v.assign(n, 0); t.assign(4 * n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    build();
    cout << query(1, 0, n - 1, 6) << endl << query(1, 0, n - 1, 5);
    return 0;
}
