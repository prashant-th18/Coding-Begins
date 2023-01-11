class Solution {
public:
    int search(vector<int>& v, int tar) {
        int s = 0, e = v.size() - 1;
		while(s <= e) {
			int mid = (s + e) >> 1;
			if(v[mid] == tar) return mid;
			else if(v[mid] < tar) s = mid + 1;
			else e = mid - 1;
		}
		return -1;
    }
};
