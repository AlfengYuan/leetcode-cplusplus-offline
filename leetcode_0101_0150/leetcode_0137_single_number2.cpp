class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int, int> mymap;
        for(int &i:nums)
        {
            mymap[i] += 1;
        }

        for(map<int, int>::iterator iter = mymap.begin(); iter != mymap.end(); iter++)
        {
            if(iter->second == 1) return iter->first;
        }

        return -1;
    }
};