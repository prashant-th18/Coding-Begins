#include<bits/stdc++.h>
using namespace std;
struct team {
    int left, right;
    team(int l = 0, int r = 0) {
        left = l, right = r;
    }
};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, k, uni = 0; cin >> n >> k;
    vector<int> v(n);
    vector<int> ind(n + 2, -1);
    set<int, greater<int>> st;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        ind[v[i]] = i;
        st.insert(i + 1);
    }
    vector<team> ans(n);
    for (int i = 0; i < n; i++) {
        if(i == 0)
        {
            ans[i].left = -1;
            if(i + 1 < n) ans[i].right = v[i + 1];
            else ans[i].right = -1;
        }
        else if(i == n - 1)
        {
            ans[i].right = -1;
            if(i - 1 >= 0) ans[i].left = v[i - 1];
            else ans[i].left = -1;
        }
        else
        {
            ans[i].left = v[i - 1];
            ans[i].right = v[i + 1];
        }
    }
    string res = string(n, '.');
    auto do_it = [&](int index) -> void
    {
          res[index] = (uni % 2) + '1';
          int c = 0, r = ans[index].right, l = ans[index].left;
          st.erase(st.begin());
          while(c < k && r != -1)
          {
              st.erase(r);
              res[ind[r]] = (uni % 2) + '1';
              r = ans[ind[r]].right;
              ++c;
          }
          c = 0;
          while(c < k && l != -1)
          {
              st.erase(l);
              res[ind[l]] = (uni % 2) + '1';
              l = ans[ind[l]].left;
              ++c;
          }
          if(l != -1)
          {
              ans[ind[l]].right = r;
          }
          if(r != -1) {
              ans[ind[r]].left = l;
          }
          ++uni;
    };
    for(int i = n; i >= 1; --i)
    {
        if(st.count(i))
        {
            do_it(ind[i]);
        }
    }
    cout << res;
    return 0;
}
