class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mymap;
        for(int i = 0; i<nums.size(); i++){
            int num = target- nums[i];
            if(mymap.find(num) != mymap.end()){
                return {mymap[num], i};
            }
            mymap[nums[i]] = i;
        }

        return {-1, -1};
    }
};