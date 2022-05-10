class Solution {
public:
    string multiply(string num1, string num2) {
        const int N = 1000;
        vector<int> res(N, 0);
        vector<int> carry(N, 0);
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int n2 = num2.size(), n1 = num1.size();
        if(n2 > n1) {
            swap(n2, n1);
            swap(num1, num2);
        }
        for(int i = 0; i < n2; ++i) {
            int a = num2[i] - '0';
            for(int j = 0; j < n1; ++j) {
                int b = num1[j] - '0';
                int p = a * b + carry[j];
                int r = p % 10;
                int c = p / 10;
                carry[j + 1] += c;
                res[i + j] += r;
                carry[j] = 0;
            }
            for(int ii = n1; ii + i < N; ++ii) {
                res[ii + i] += carry[ii] % 10;
                if(ii != N - 1)
                carry[ii + 1] += carry[ii] / 10;
                carry[ii] = 0;
            }
            carry.assign(N, 0);
        }
        for(int i = 0; i < N - 1; ++i) {
            int num = res[i];
            res[i] = num % 10;
            res[i + 1] += num / 10;
        }
        string result = "";
        bool flag = false;
        reverse(res.begin(), res.end());
        for(int i = 0; i < N; ++i) {
            if(res[i] != 0) { flag = true; }
            if(flag) result += to_string(res[i]);
        }
        if(result == "") result = "0";
        return result;
    }
};
