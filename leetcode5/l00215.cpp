class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> mypq(nums.begin(), nums.end());
        while (--k) {
            mypq.pop();
        }

        return mypq.top();
    }
};