class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> mymap;
        for(int &i: nums){
            if(mymap.count(i) == 0){
                mymap[i] = 1;
            }else{
                mymap[i]++;
            }
        }

        vector<int> vec;
        int comp = nums.size() / 3;
        //if(nums.size() % 3 != 0) comp++;

        for(auto &v: mymap){
            if(v.second > comp) vec.push_back(v.first);
        }

        return vec;
    }
};