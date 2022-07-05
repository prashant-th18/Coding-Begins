// In this question, we will use a different version of segment tree.
// The different version is ->
// At each node of the segment tree, we will keep all the elements of the segment at that node (maybe sorted 
// or in some advanced DS (map, set))

// This version of Seg Tree is also known as Merge Sort Tree, as this is a variant of Seg Tree and in the build
// section, the t[in] is made like in the Merge Sort


// Question is ->
// Given a range and a number (l, r, x) -> Find the smallest number present in range a[l .. r], such that it is 
// >= x

#include<bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;
int n;
vector<int> v;

// No modification in the array
// In this version, we will keep all the elements at a node in sorted order in a vector
/*vector<vector<int>> t;
void build(int in = 1, int s = 0, int e = n - 1) {
    if(s == e) {
        t[in] = vector<int>(1, v[s]);
    }
    else {
        int mid = (s + e) / 2;
        build(2 * in, s, mid);
        build(2 * in + 1, mid + 1, e);
        // Now you need to store the vector t[2 * in] & t[2 * in + 1] in sorted order in t[in]
        // Using STL
        merge(t[2 * in].begin(), t[2 * in].end(), t[2 * in + 1].begin(), t[2 * in + 1].end(), 
                back_inserter(t[in]));
    }
}
int query(int in, int s, int e, int qs, int qe, int x) {
    if(qs > qe) {
        return INF;
    }
    if(s == qs && e == qe) {
        // Return the smallest number greater than x
        auto it = lower_bound(t[in].begin(), t[in].end(), x);
        if(it != t[in].end()) return *it;
        return INF; // All numbers are smaller than x
    }
    int mid = (s + e) / 2;
    return min(query(2 * in, s, mid, qs, min(mid, qe), x), query(2 * in + 1, mid + 1, e, max(mid + 1, qs), qe, x));
}
*/
// Second Version 
// Modification Allowed
vector<multiset<int>> t;
void build(int in = 1, int s = 0, int e = n - 1) {
    if(s == e) {
        t[in].insert(v[s]);
    }
    else {
        int mid = (s + e) / 2;
        build(2 * in, s, mid);
        build(2 * in + 1, mid + 1, e);
        merge(t[2 * in].begin(), t[2 * in].end(), t[2 * in + 1].begin(), t[2 * in + 1].end(), 
                back_inserter(t[in]));
    }
}
void update(int in, int s, int e, int pos, int nval) {
    t[in].erase(t[in].find(v[pos]));
    t[in].insert(nval);
    if(s == e) {
        v[pos] = nval;
    }
    else {
        int mid = (s + e) / 2;
        if(pos <= mid) update(2 * in, s, mid, pos, nval);
        else update(2 * in + 1, mid + 1, e, pos, nval);
    }
}
// query function is similiar as the first version 
int main() {
    cin >> n;
    v.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    // First Version
    // t.assign(4 * n, vector<int>());
    // Second Version
    t.assign(4 * n, multiset<int>());
    build();
    cout << query(1, 0, n - 1, 0, n - 1, 2);
    return 0;
}
