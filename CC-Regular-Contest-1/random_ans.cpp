#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define sz(x) ((int)x.size())
#define ff first
#define ss second
#define all(x) begin(x), end(x)
// *-> KISS*
int32_t main() {
    fstream fin, fout;
    fin.open("in17.in", ios :: in);
    fout.open("in17.out", ios :: out | ios :: trunc);
    int t; fin >> t;
    while(t--)
    {
        int n; fin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            fin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            fin >> b[i];
        }
        // a|b - a&b
        for (int i = 0; i < n; i++) {
            bool flag = true;
            int x = a[i] - b[i];
            if(x < 0) x = -1;
            else
            {
                for(int j = 0; j < 31; ++j)
                {
                    if((((1 << j) & b[i]) != 0) && (((1 << j) & a[i]) == 0))
                    {
                        flag = false; break;
                    }
                }
                if(!flag) x = -1;
            }
            fout << x << ' ';
        }
        fout << '\n';
    }
    return 0;
}
// -> Keep It Simple Stupid!
