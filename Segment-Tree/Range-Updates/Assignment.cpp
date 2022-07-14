// Query is
// -> (l, r, x) -> From range "l" to "r", assign all the values of the array to "x"
//
// Now, If you think it in a naive approach, you will go down to all the indices and update them to "x"
// But, the same thing can be done in O(logn) using "lazy propagation"
//
// As the name suggests, we are lazy in updating all the values
// i.e. Suppose the query is (0, n - 1, x) i.e. to update all the elements of the array to "x"
//
// So instead of changing all the values, we see that the first node i.e node with range [0 .. n - 1] covers all
// the elements we need to change. So instead of changing all the elements, we say that, on this segment, we
// are updating the value.
//
// Now, if someone wants to get the value of a[n - 2], we can directly give it the value stored in the first 
// segment as it is applied from [0 .. n - 1]
//
// But, now suppose that again a query comes (0, n / 2, y)
// So, in this query, only the left child is updated, so now we got to know the first segment(0..n - 1) can't be
// used, so we say that okay this is unusable now, and we set value to segment (0..n/2) -> y
//
// But, you should have noticed until now, that the right child (n/2 + 1, n - 1) is storing nothing, although 
// it should store value "x" as first segment is unusable but it has assigned a value "x" to every element
//
// So, it is necessary that everytime we have a update query, we should paas the info present in the parent to
// it's child nodes
// so that values are preserved and time complexity for update query remains O(logN)

#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> v, t;
vector<bool> marked;
void push(int in) {
    if(marked[in]) {
        t[2 * in] = t[2 * in + 1] = t[in];
        marked[2 * in] = marked[2 * in + 1] = true;
        marked[in] = false;
    }
}
void update(int in, int s, int e, int qs, int qe, int nval) {
    if(qs > qe) return;
    if(s == qs && e == qe) {
        marked[in] = true;
        t[in] = nval;
    }
    else {
        push(in);
        int mid = (s + e) / 2;
        update(2 * in, s, mid, qs, min(mid, qe), nval);
        update(2 * in + 1, mid + 1, e, max(qs, mid + 1), qe, nval);
    }
}
int get(int in, int s, int e, int pos) {
    if(s == e || marked[in]) {
        return t[in];
    }
    int mid = (s + e) / 2;
    if(pos <= mid) return get(2 * in, s, mid, pos);
    else return get(2 * in + 1, mid + 1, e, pos);
}
int main() {
    cin >> n;
    // v.assign(n, 0);
    t.assign(4 * n, 0);
    marked.assign(4 * n, false); 
    // if marked[i] is true, that means a single value is applied to the whole segment of i
    // for (int i = 0; i < n; i++) {
    //    cin >> v[i];
    // }
    update(1, 0, n - 1, 0, 3, 2);
    update(1, 0, n - 1, 2, 3, 3);
    cout << get(1, 0, n - 1, 1) << ' ' << get(1, 0, n - 1, 2);
    return 0;
}
