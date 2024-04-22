class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        int index = nums.size()-1-k;
        stack<int> mystack;
        for(int i = index; i>=0; i--){
            mystack.push(nums[i]);
        }

        for(int j = nums.size()-1; j>index; j--){
            mystack.push(nums[j]);
        }

        for(int i = 0; i<nums.size(); i++){
            nums[i] = mystack.top();
            mystack.pop();
        }
    }
};