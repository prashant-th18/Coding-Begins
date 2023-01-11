#include "bits/stdc++.h"
using namespace std;
#define sz(x) ((int)x.size())
const int MAXN = 1e6;
int main() {
	vector<bool> is_composite(MAXN, false);
	vector<int> prime;
	for(int i = 2; i < MAXN; ++i) {
		if(!is_composite[i]) prime.push_back(i);
		for(int j = 0; j < sz(prime) && prime[j] * i < MAXN; ++j) {
			is_composite[i * prime[j]] = true;
			if(i % prime[j] == 0) {
				break;
			}
		}
	}
	return 0;
}
