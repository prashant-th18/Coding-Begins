/*

We have sorted projects on the basis of their ending points (increasing order)

DP State -> dp(i) : Maximum reward I can get from [P1, P2, ... Pi] where P stands for a project

Answer -> dp(n)

Recurrence Relation ->
             dp(i - 1) // Not taking the ith project
dp(i) = MAX 
             r_i + dp(j) // where j is the maximum index whose ending point (e_j) < starting point of "i" (s_i)

Base Case -> dp(0) = 0
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int bestIndex(vector<ll>& endPoints, int ind, int start) { // start denotes the starting day of current Project
    // Since Currently I am dealing with project of index "ind", I have to choose a project from index "0" to "ind - 1"
    int s = 0, e = ind - 1, ans = -1;
    while(s <= e) {
        int mid = (s + e) >> 1;
        if(endPoints[mid] < start) {
            ans = mid; s = mid + 1;
        }
        else {
            e = mid - 1;
        }
    }
    return ans;
}
int main() {
    int n; cin >> n; // Number of Projects
    vector<array<ll, 3>> v(n); // Storing starting point, ending point and reward of ith project
    vector<ll> endPoints; // Storing endPoints
    for (int i = 0; i < n; i++) {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
        endPoints.push_back(v[i][1]);
    }
    // Sorting them on the basis of their ending point
    sort(v.begin(), v.end(), [&](array<ll, 3> a, array<ll, 3> b) {
        return a[1] < b[1];
    });
    sort(endPoints.begin(), endPoints.end());
    vector<ll> dp(n + 1);
    dp[0] = 0; // Not taking any project into consideration
    for(int i = 1; i <= n; ++i) {
        ll op1 = dp[i - 1]; // Don't take this project
        ll op2 = v[i - 1][2]; // Take this project and valid projects behind it
        int ind = bestIndex(endPoints, i - 1, v[i - 1][0]);
        op2 += dp[ind + 1];
        dp[i] = max(op1, op2);
    }
    cout << dp[n];
    return 0;
}
