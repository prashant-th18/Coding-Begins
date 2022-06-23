/*

DP State -> dp(a, b) : Minimum cuts required to cut a rectangle of size (a X b) into a bunch of squares

Ans -> dp(n, m)

Base Case -> dp(a, a) = 0 (for all a) (Because a rectangle of size a * a is already a square)

Recurrence ->
*/
#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(i == j) {
                // Base Case
                dp[i][j] = 0;
            }
            else {
                // Assume rectangle like ->
                // i X j ( i -> length,  j -> breadth )
                // Either I can make a horizontal cut from "1" to "i - 1"
                // Or I can make a vertical cut from "1" to "j - 1"
                int mini = INT_MAX;
                for(int h = 1; h <= i - 1; ++h) {
                    mini = min(mini, 1 + dp[i - h][j] + dp[h][j]);
                    // After cutting horizontally, I am left with two rectangles of size ->
                    // (i - h) * j  AND  (h) * j
                    // And these values can be get from dp 
                }
                for (int w = 1; w <= j - 1; w++) {
                    mini = min(mini, 1 + dp[i][w] + dp[i][j - w]);
                }
                dp[i][j] = mini;
            }
        }
    }
    // Space Complexity -> O(n * m)
    // Time Complexity -> O(n * m * (n + m))
    cout << dp[n][m]; // Answer
    return 0;
}
