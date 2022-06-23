#ifdef LOCAL
    #define _GLIBCXX_DEBUG
#endif
// #pragma GCC optimize("O3")
// #pragma GCC target("popcnt")
#include "bits/stdc++.h"
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
#define M 31;

struct node {
  int count;

  node* arr[2];
};
node* getNode() {
    node* n = new node;
    n -> count = 0;

    n -> arr[0] = n -> arr[1] = nullptr;
    return n;
}
void insert(node* root, int num) {
    // Reverse the binary representation of num
    vector<int> bit(31, 0);
    for(int i = 0; i < 31; ++i) bit[i] = ((num >> i) & 1);
    node* temp = root;
    (temp -> count)++;

    for(int i = bit.size() - 1; i >= 0; --i) {
        int t = bit[i];
        if(temp -> arr[t] == nullptr) temp -> arr[t] = getNode();
        temp = temp -> arr[t];
        (temp -> count)++;
    }
}
void del(node* root, int num) {
    vector<int> bit(31, 0);
    for (int i = 0; i < 31; i++) {
        bit[i] = ((num >> i) & 1);
    }
    node* temp = root;
    (temp -> count)--;
    for(int i = bit.size() - 1; i >= 0; --i) {
        int t = bit[i];
        temp = temp -> arr[t];
        (temp -> count)--;
    }
}
int cal(node* root, int num) {
    vector<int> bit(31, 0);
    for(int i = 0; i < 31; ++i) bit[i] = ((num >> i) & 1);

    node* temp = root;
    int ans = 0;
    if(temp -> count == 0) return ans;
    
    for(int i = bit.size() - 1; i >= 0; --i) {
        int t = bit[i]; t = 1 - t;
        if(temp -> arr[t] != nullptr && temp -> arr[t] -> count != 0) {
            ans += (1 << i);
            temp = temp -> arr[t];
        }
        else {
            t = 1 - t;
            if(temp -> arr[t] != nullptr && temp -> arr[t] -> count != 0) {
                temp = temp -> arr[t];
            }
            else break;
        }
    }
    return ans;
}
// *-> KISS*
int solve() {
    node* root = getNode();
    insert(root, 0);
    int q; cin >> q;
    while(q--) {
        char ch; cin >> ch;
        int num; cin >> num;
        if(ch == '+') {
            insert(root, num);
        }
        else if(ch == '-') del(root, num);
        else cout << cal(root, num) << '\n';
    }
    return 0;
}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool test = false;
    int TET = 1;
    if(test) cin >> TET;
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
