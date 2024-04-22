class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
		unordered_map<int, bool> mymap;
		int res = 0;
		for (int& num : nums) {
			if (mymap.count(num) == 0) {
				mymap[num] = true;
			}
		}

		for (auto& v : mymap) {
			int start = v.first;
			if (!mymap[start]) continue;
			int left = start, right = start;
			while (mymap.count(left) > 0) {
				mymap[left] = false;
				left--;
			}
			while (mymap.count(right) > 0) {
				mymap[right] = false;
				right++;
			}
			res = max(res, right-left-1);
		}

		return res;

    }
};