/*
 * There is an elevator with
maximum weight x, and n people with known weights who want to get from the
ground floor to the top floor. What is the minimum number of rides needed if the
people enter the elevator in an optimal order?
*/
#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, x; cin >> n >> x; // n -> persons, x -> maximum weight
    vector<int> w(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    pair<int, int> best(1 << n);
    // best[i] -> stores a pair where first thing store for subset "i", how many rides we have to do
    // and second thing store "Since, we have done some number of rides. In each ride, we have taken
    // some persons whose total weight is <= x.
    // So in all these groups, we take the one whose total weight is smallest. 
    // This is the second thing.
    best[0] = {1, 0}; // If no-one is selected, then we assume that 1 ride is taken and minimum weight of 
                      // group is 0
    for(int i = 1; i < (1 << n); ++i) {
        // initial value: n+1 rides are needed
        best[i] = {n + 1, 0};
        for(int p = 0; p < n; ++p) {
            if(i & (1 << p)) {
                auto option = best[i ^ (1 << p)];
                if(option.second + w[p] <= x) {
                    // add p to an existing ride
                    option.second += w[p];
                }
                else {
                    // reserve a new ride for p
                    option.first++;
                    option.second = w[p];
                }
                best[i] = min(best[i], option);
            }
        }
    }
    cout << best[(1 << n) - 1];
    return 0;
}
