/*
    Author : prashant_th18
                            :)
*/
// Lecture 5 Binary Search, Copy - 14
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ull unsigned long long
#define ll long long
#define ld long double
#define pi pair<int, int>
#define pl pair<ll, ll>
#define m_p make_pair
#define vl vector<ll>
#define vi vector<int>
#define vpi vector<pi>
#define vpl vector<pl>
#define vd vector<double>
#define pb push_back
#define mll map<ll, ll>
#define be(v) begin(v), end(v)
#define fl(i, si, ei) for(ll i = si; i < ei; ++i)
#define nline "\n"
#define space " "
#define size(a) (int)a.size()
void debug(int x){
#ifndef ONLINE_JUDGE 
    cout << "The value is : " << x << nline; 
#endif
}
void solve()
{
    int books, students;
    cin >> books >> students;
    vi v(books);
    ll sum = 0;
    fl(i, 0, books)
    {
        cin >> v[i];
        sum += v[i];
    }
    // starting point is assigned as "v[0]" as it is the minimum possible among all possible ways
    // e is assigned as sum, as sum of all pages is the maximum possible among all ways.    
    int s = v[0], e = sum, ans = -1;
    while(s <= e)
    {
         int mid = (s + e) / 2;
         int cnt = 1, temp = 0; 
         bool m = false;
         // Here cnt will tell about the total number of students that will read all books
            fl(k, 0, books)
            {
                  temp += v[k];
                  // temp will keep the number of pages being read by a student
                  if (temp > mid)
                  {
                      ++cnt;
                      if (cnt > students)
                      {
                          m = true;
                          break;
                      }
                      temp = v[k];
                  }
            }
            // Below if else will update "s" to mid + 1, so that now more pages therefore
            // given number of students might be able to read all the pages.
        if (cnt > students || m)
        {
            s = mid + 1;
        }
        else if (cnt == students)
        {
            // right configuration found but will search in s to mid - 1 so as to see 
            // if a better config is available.
            e = mid - 1;
            ans = mid;
        }
        else
        {
            e = mid - 1;
        }
    }
    cout << ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    while (t--) {
        solve();
        cout << nline;
    }
  
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}   