// Binary Indexed Tree to calculate the sum of a range
/*
 * Let's first get to know, what will be stored at each index of bit array.
 * So, at each index of bit array, we will be storing a partial sum(consecutive elements sum)
 *
 * Suppose, we are given an array of size "n"
 * BIT -> 1, 2, 3, ... 7, 8, 9, 10, 11, 12, 13 ( 0 is ignored )
 *
 * What will bit[i] store?
 * Suppose, we have two indices "i" and "j"
 * So, bit[i] = sum from index "j + 1" to index "i" of original array
 * j => remove last bit of i => j = i - (i & -i)
 *
 * Eg: 13 -> 1101, In this case, j = 1100, therefore, bit[13] = sum[13, 13]
 *     12 -> 1100, In this case, j = 1000, therefore, bit[12] = sum[9, 12]
 *
 * Suppose, I want to calculate the sum from [1, 13] ->
 * sum = bit[13] + bit[12] + bit[8]
 *
 *
 * Suppose, I want to add something to the index "13" of the original array
 * So, I have to add the addend to all the bit's whose range contains 13
 * For eg:
 * bit[13] ke liye j -> 12, So sum = 13 -> 13. therefore we will add addend to bit[13]
 * bit[14] ke liye j -> 12, So sum = 13 -> 14, therefore, addend will be added to bit[14]
 *
 * So, basically suppose, index "i" pr "x" addend add krna chahta hun
 * So, index "i" se un sbhi "bit" elements pr addend krte jaaenge jinko hm smallest set bit ko add krke bnaenge
 * 
 * Eg.: 13 (1101) -> 14 (1110) -> 16 (10000) -> 32 (100000)
 */
#include"bits/stdc++.h"
using namespace std;
int n;
vector<int> bit, v; // 1 - Based
int sum(int i) {
    int s = 0;
    for(; i > 0; i -= (i & (-i))) {
        s += bit[i];
    }
    return s;
    // Time Complexity -> log2(i)
}
void update(int i, int x) {
    for(; i <= n; i += (i & (-i))) {
        bit[i] += x;
    }
}
int main() {
    cin >> n;
    v.assign(n, 0); bit.assign(n + 1, 0);
    for(int i = 0; i < n; ++i) cin >> v[i];
    // To calculate the sum from index "1" to index "i" (Remember 1 Based)
    // cout << sum(5);
    //
    // To calculate the sum of a range
    // cout << sum(5) - sum(2);
    return 0;
}
