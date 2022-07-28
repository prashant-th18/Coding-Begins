#define sz(x) ((int)x.size())
/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    vector<int> in;
    int dfs(int index, vector<Employee*>& e) {
        int sum = 0;
        sum += e[index] -> importance;
        for(int i : e[index] -> subordinates) {
            sum += dfs(in[i], e);
        }
        return sum;
    }
    int getImportance(vector<Employee*> e, int id) {
        in.assign(2001, 0);
        for (int i = 0; i < sz(e); i++) {
            in[e[i] -> id] = i;
        }
        return dfs(in[id], e);
    }
};
