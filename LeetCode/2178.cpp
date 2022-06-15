class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        vector<long long> split;
        if(finalSum & 1) return split;

        long long cur = 2, sum = 0;
        while(finalSum - (sum + cur) > cur) {
            sum += cur;
            split.emplace_back(cur);
            cur += 2;
        }
        if(finalSum - sum > 0) split.emplace_back(finalSum - sum);
        return split;
    }
};
