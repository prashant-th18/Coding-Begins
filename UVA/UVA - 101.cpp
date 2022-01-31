/*
    Author : prashant_th18
                            :)
*/
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
void debug(int x) {
#ifndef ONLINE_JUDGE
    cout << "The value is : " << x << nline;
#endif
}
template <typename A>
A MIN(A a, A b)
{
    if (a < b) return a;
    return b;
}
template <typename A>
A gcd(A a, A b)
{
    while (b) a %= b, swap(a, b);
    return a;
}
void solve()
{
    int n;
    cin >> n;
    map<int, int> mp;
    fl(i, 0, n)
    {
        mp[i] = i;
    }
    deque<deque<int>> v(n);
    fl(i, 0, n)
    {
        v[i].pb(i);
    }
    while (1)
    {
        string s;
        getline(cin, s);
        istringstream iss(s);
        string first, second;
        iss >> first;
        if (first == "quit")
        {
            break;
        }
        int n1, n2;
        iss >> n1;
        iss >> second;
        iss >> n2;
        int pos1, pos2;
        pos1 = mp[n1], pos2 = mp[n2];
        if (pos1 == pos2) continue;
        if (first == "move" && second == "onto")
        {
            for (int i = (int)v[pos1].size() - 1; i >= 0; --i)
            {
                if (v[pos1][i] != n1)
                {
                    v[v[pos1][i]].push_back(v[pos1][i]);
                    mp[v[pos1][i]] = v[pos1][i];
                    v[pos1].pop_back();
                }
                else if (v[pos1][i] == n1)
                {
                    v[pos1].pop_back();
                    break;
                }
            }
            for (int i = (int)v[pos2].size() - 1; i >= 0; --i)
            {
                if (v[pos2][i] != n2)
                {
                    v[v[pos2][i]].push_back(v[pos2][i]);
                    mp[v[pos2][i]] = v[pos2][i];
                    v[pos2].pop_back();
                }
                else if (v[pos2][i] == n2)
                {
                    break;
                }
            }
            v[pos2].push_back(n1);
            mp[n1] = pos2;
        }
        else if (first == "move" && second == "over")
        {
            for (int i = (int)v[pos1].size() - 1; i >= 0; --i)
            {
                if (v[pos1][i] != n1)
                {
                    v[v[pos1][i]].push_back(v[pos1][i]);
                    mp[v[pos1][i]] = v[pos1][i];
                    v[pos1].pop_back();
                }
                else if (v[pos1][i] == n1)
                {
                    v[pos1].pop_back();
                    break;
                }
            }
            v[pos2].push_back(n1);
            mp[n1] = pos2;
        }
        else if (first == "pile" && second == "onto")
        {
            for (int i = (int)v[pos2].size() - 1; i >= 0; --i)
            {
                if (v[pos2][i] != n2)
                {
                    v[v[pos2][i]].push_back(v[pos2][i]);
                    mp[v[pos2][i]] = v[pos2][i];
                    v[pos2].pop_back();
                }
                else if (v[pos2][i] == n2)
                {
                    break;
                }
            }
            stack<int> mystack;
            for (int i = (int)v[pos1].size() - 1; i >= 0; --i)
            {
                if (v[pos1][i] != n1)
                {
                    mystack.push(v[pos1][i]);
                    v[pos1].pop_back();
                }
                else if(v[pos1][i] == n1)
                {
                    mystack.push(v[pos1][i]);
                    v[pos1].pop_back();
                    break;
                }
            }
            while(!mystack.empty())
            {
                v[pos2].push_back(mystack.top());
                mp[mystack.top()] = pos2;
                mystack.pop();
            }
        }
        else
        {
            stack<int> mystack;
            for (int i = (int)v[pos1].size() - 1; i >= 0; --i)
            {
                if (v[pos1][i] != n1)
                {
                    mystack.push(v[pos1][i]);
                    v[pos1].pop_back();
                }
                else if(v[pos1][i] == n1)
                {
                    mystack.push(v[pos1][i]);
                    v[pos1].pop_back();
                    break;
                }
            }
            while(!mystack.empty())
            {
                v[pos2].push_back(mystack.top());
                mp[mystack.top()] = pos2;
                mystack.pop();
            }
        }
    }
    for(int i = 0; i < n; ++i)
    {
        cout << i << ":";
        if ((int)v[i].size() != 0)
        {
            for(auto val : v[i])
            {
                cout << " " << val;
            }
        }
        cout << nline;
    }
}
int main()
{
    cout << fixed << setprecision(0);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int t = 1;
    while (t--) {
        solve();
        // cout << nline;
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}