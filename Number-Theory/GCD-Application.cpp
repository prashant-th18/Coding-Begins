#include <bits/stdc++.h>
using namespace std;

array<int, 3> GCD(int a, int b) {
	
	// returns {d, x, y}
	
	// At this moment, we say that, 
	// ax + by = d
	// the above equation is true
	
	// return 3 things
	// [0] -> gcd of (a, b)
	// [1] -> the value of x
	// [2] -> the value of y
	
	if(b == 0) {
		return array<int, 3>({a, 1, 0});
		
		// a * (1) + b * (0) = a
	}
	else {
		array<int, 3> t = GCD(b, a % b);
		
		int d = t[0], x = t[1], y = t[2];
		
		// Therefore the equation is 
		
		// b * x + (a % b) * y = d
		// OR
		// b * x + (a - (a / b) * b) * y = d
		
		// (x - y * (a / b)) * b + (y * a) = d
		
		return array<int, 3>({d, y, x - y*(a/b)});
	}
}
int main() {
	// Suppose we want to find solution for the equation
	
	// ax + by = c  ---- 1
	// Suppose, d = gcd(a, b)
	
	// If d divides c, then solution exists, otherwise it doesn't
	
	// So, we will solve this equation for
	// ax + by = d
	
	// And since, d divides c, we will multiply x and y and d with (c / d)
	// And we get our equation 1
	
	return 0;
}