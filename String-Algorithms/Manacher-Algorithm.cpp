// Given a string, find longest palindromic substring in this string in linear time.
#include<bits/stdc++.h>
using namespace std;
int main() {
    string p; cin >> p;
    string s = "$";
    for(int i = 0; i < p.size(); ++i) {
        s += p[i];
        s += "$";
    }
    int n = s.size();
    vector<int> pi(n, 1);
    // Which index to make head?
    // -> Palindrome totally contained inside current palindrome => NO
    // -> Current Palindrome expands till end of input => Stop the process
    // -> Palindrome expands till right edge & it's mirror palindrome is prefix => YES
    // -> Palindrome expands till right edge & it's mirror expands beyond left edge => NO
    int head = 0;
    for(int i = 0; i < n; ++i) {
        // head + pi[head] / 2
        if(i <= head + pi[head] / 2) {
             int diff = i - head;
             int ind = head - diff;
             int lower = ind - pi[ind] / 2;
             int hlower = head - pi[head] / 2;
             if(lower < hlower) pi[i] = pi[ind] - (hlower - lower) * 2;
             else if(pi[ind] / 2 + i < head + pi[head] / 2) pi[i] = pi[ind];
             else {
                 head = i;
                 pi[i] = pi[ind];
                 int j = i - pi[ind] / 2 - 1, k = i + pi[ind] / 2 + 1;
                 int cnt = 0;
                 while(j >= 0 && k < n && s[j] == s[k]) cnt += 2, --j, ++k;
                 pi[i] += cnt;
                 if(k == n) break;
             }
        }
        else {
            head = i;
            int j = i - 1, k = i + 1, cnt = 0;
            while(j >= 0 && k < n && s[j] == s[k]) cnt += 2, --j, ++k;
            pi[i] += cnt;
            if(k == n) break;
        }
    }
    int ind = -1, maxx = 0;
    for(int i = 0; i < n; ++i) {
        if(pi[i] > maxx) {
            maxx = pi[i];
            ind = i;
        }
    }
    cout << maxx << ' ' << ind << ' ' << (s.substr(ind - maxx / 2, maxx));
    return 0;
}
