#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        if(x < 0) {
            string comp = to_string(INT_MAX);
            comp[comp.size() - 1] = ((comp[comp.size() - 1] - '0') + 1) + '0';
            comp = "-" + comp;
            if(x == INT_MIN) return 0;
            string integer = to_string(-x);
            ::reverse(integer.begin(), integer.end());
            integer = "-" + integer;
            bool flag = true;
            for(int i = 0; integer.size() == comp.size() && i < integer.size(); ++i) {
                if(comp[i] < integer[i]) {
                    flag = false; break;
                }
                else if(comp[i] > integer[i]) break;
            }
            if(flag == false) return 0;
            else return stoi(integer);
        }
        else {
            string comp = to_string(INT_MAX);
            string integer = to_string(x);
            ::reverse(integer.begin(), integer.end());
            bool flag = true;
            for(int i = 0; integer.size() == comp.size() && i < integer.size(); ++i) {
                if(comp[i] < integer[i]) {
                    flag = false; break;
                }
                else if(comp[i] > integer[i]) break;
            }
            if(!flag) return 0;
            else return stoi(integer);
        }
    }
};
