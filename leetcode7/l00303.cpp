class NumArray {
    vector<int> mynums;
public:
    NumArray(vector<int>& nums) {
        mynums.assign(nums.begin(), nums.end());
    }
    
    int sumRange(int left, int right) {
        return accumulate(mynums.begin()+left, mynums.begin()+right+1, 0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */