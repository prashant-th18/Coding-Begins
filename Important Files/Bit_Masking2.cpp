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
// Counting number of setbits in a number
int countsetbit(int n)
{
    int cnt = 0;
    while (n != 0)
    {
        ++cnt;
        n = n & (n - 1);
    }
    return cnt;
}
// Swapping Numbers using XOR
void swap_XOR(int &a, int &b)
{
    int res = a ^ b;
    a = res ^ a;
    b = res ^ b;
}
// Function to find ith bit
int find_ith_bit(int number, int i)
{
    return ((number >> i) & 1);
}
// Function to set ith bit(if that bit is 0)
void setBit(int &number, int i)
{
    number = (number | (1 << i));
}
// Clears the bit at the given index(means changing 1 -> 0 at that point)
void clearBit(int &number, int i)
{
    int mask = 1 << i;
    number = (number ^ mask);
}
void solve()
{
    int n = 12;
    // cin >> n;
    clearBit(n, 2);
    cout << n;
}
int main()
{
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