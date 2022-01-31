#ifdef LOCALL
// https://github.com/AkshatAggarwal14/Competetive-Programming
#include "Akshat.hpp"
#else
#include "bits/stdc++.h"
using namespace std;
#define dbg(...)
#endif
using ll = int64_t;
auto sz = [](const auto &container) -> int { return container.size(); };
#define all(x) (x).begin(), (x).end()
template <class T, class U = T>
bool amin(T &a, U &&b) { return b < a && (a = std::forward<U>(b), true); }
template <class T, class U = T>
bool amax(T &a, U &&b) { return a < b && (a = std::forward<U>(b), true); }
const int MOD = 1e9 + 7;

template <typename T, typename T_iterable>
vector<pair<T, ll>> compress(const T_iterable &items) {
    if (items.empty()) return {};
    vector<pair<T, ll>> encoded;
    ll count = 0;
    T last = items[0];
    for (const T &item : items) {
        if (item == last) {
            count++;
        } else {
            if (count) encoded.push_back({last, count});
            last = item, count = 1;
        }
    }
    if (count) encoded.push_back({last, count});
    return encoded;
}

void Solution() {
    ll n;
    string s;
    cin >> n >> s;
    string s1 = "", s2 = "";
    for (ll i = 0; i < n; ++i) {
        s1 += ((i & 1) + '0');
        s2 += (((i + 1) & 1) + '0');
    }
    dbg(s1, s2);
    vector<bool> v1(n), v2(n);
    for (ll i = 0; i < n; ++i) v1[i] = (s[i] == s1[i]), v2[i] = (s[i] == s2[i]);
    auto c1 = compress<bool>(v1), c2 = compress<bool>(v2);
    dbg(c1, c2);
    ll g1 = 0, g2 = 0, cnt1 = 0, cnt2 = 0;
    for (auto &[x, y] : c1)
        if (x == false) g1++, cnt1 += y;
    for (auto &[x, y] : c2)
        if (x == false) g2++, cnt2 += y;
    if (cnt1 == cnt2) {
        cout << (((g1 & 1) || (g2 & 1)) ? "JJ\n" : "Uttu\n");
    } else {
        if (amin(cnt1, cnt2)) amin(g1, g2);
        cout << ((g1 & 1) ? "JJ\n" : "Uttu\n");
    }
    // cout << (((g1 & 1) || (g2 & 1)) ? "JJ\n" : "Uttu\n");
}

void alternate() {
    // 0101010101010
    // 1010101010101
    int n;
    cin >> n;
    string s;
    cin >> s;
    string a, b;
    for (int i = 0; i < n; i++) {
        if(i & 1)
        {
            a += "1"; b += "0";
        }
        else a += "0", b += "1";
    }
    if(s == a || s == b)
    {
        cout << "Uttu";
    }
    else cout << "JJ";
    cout << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(12);
    int tc = 1;
    cin >> tc;
    while (tc--) {
        // Solution();
        alternate();
    }
    return 0;
}
