class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, bool> mymap;
        for(int &num: nums){
            if(mymap.count(num)) return true;
            mymap[num] = true;
        }

        return false;

    }
};