/*
 * Observation:
 * In Potential Candidates Set,
 * 1. Sorted Values => Sorted Advantage
 * 2. For same advantage, keep smaller value.
*/
#include<bits/stdc++.h>
using namespace std;
int getBestCandidate(map<int, int>& mp, int v) {
    auto it = mp.lower_bound(v);
    if(it == mp.begin()) {
        // So there doesn't exist any value smaller than v, therefore returning 0
        return 0;
    }

    --it; // Getting the iterator pointing to smaller value
    return (it -> second); // Returning the advantage of the value just smaller than "v" because it is the only 
                           // one which provides this maximum advantage and it is smaller than "v".
}
void insert(map<int, int>& mp, int value, int adv) { // Map, Value, Advantage
    
    if(mp[value] >= adv) {
        return;
        // Agar pehle hi exist krta hai aur uski advantage ab ki baar ke advantage se jyada hai toh ab ki baar 
        // ka koi importance nhi rehta
    }
    mp[value] = adv;
    auto it = mp.find(value);
    // it will store iterator pointing to pair -> {value, adv}
    // So, now I have to remove all the necessary pairs ahead of "it" which are now not valid.
    // Which are now not valid?
    // Suppose before I have added new advantage, mp was -> { {1, 1}, {3, 2}, {5, 3}, {7, 4} }
    // After adding {6, 4} , mp ->  { {1, 1}, {3, 2}, {5, 3}, {6, 4}, {7, 4} }
    // As we can see, Keeping {7, 4} is of no use
    ++it; // Now at the next iterator
    while(it != mp.end() && (it -> second) <= adv) {
        // If km advantage de rha as compared to newly inserted, delete it
        it = mp.erase(it); // Erases Current pair and returns next pair
    }
}
int main() {
    int n; cin >> n; // Number of elements
    vector<int> v(n);
    for(int i = 0; i < n; ++i) cin >> v[i];

    vector<int> dp(n, 0); // dp[i] -> Length of LIS ending at position "i"
    map<int, int> candidates; // Keeping Potential Candidates
    // Map will keep ->  { Value(Element Value), Advantage this value will provide }

    // Base Case
    dp[0] = 1; candidates[v[0]] = 1;
    for(int i = 1; i < n; ++i) {
        dp[i] = 1 + getBestCandidate(candidates, v[i]);
        insert(candidates, v[i], dp[i]);
    }
    cout << (*max_element(begin(dp), end(dp)));
    return 0;
}
