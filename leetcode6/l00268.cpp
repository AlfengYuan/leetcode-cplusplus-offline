class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_map<int, bool> mymap;
        for(int &num: nums){
            mymap[num] = true;
        }

        for(int i = 0; i<=nums.size(); i++){
            if(mymap.count(i)) continue;
            return i;
        }

        return -1;
    }
};