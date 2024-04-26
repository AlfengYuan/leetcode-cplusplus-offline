class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<string> vec;
        for(int i = 0; i<nums.size(); i++){
            string tmp = "";
            tmp += to_string(nums[i]);
            int j = i + 1;
            while(j < nums.size() && nums[j] - 1 == nums[j-1]) j++;
            if(j > i+1){
                tmp += "->";
                tmp += to_string(nums[j-1]);
                i = j-1;
            }
            vec.push_back(tmp);
        }

        return vec;
    }
};