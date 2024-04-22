class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> mymap;
        for(int i = 0; i<numbers.size(); i++){
            if(mymap.find(target-numbers[i]) != mymap.end()){
                return {mymap[target-numbers[i]], i+1};
            }
            mymap[numbers[i]] = i+1;
        }

        return {-1, -1};
    }
};