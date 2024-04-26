class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> mymap;
        for(int &num: nums){
            if(mymap.count(num) == 0) mymap[num] = 1;
            else mymap[num]++;
        }

        vector<int> res;
        for(auto &v: mymap){
            if(v.second > 1) continue;
            res.push_back(v.first);
        }

        return res;

    }
};