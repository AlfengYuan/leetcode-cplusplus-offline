class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res(digits.size()+1, 0);
        int add = 1;
        for(int i = digits.size()-1; i>=0; i--){
            int curr = digits[i] + add;
            res[i+1] = curr % 10;
            add = curr /10;
        }
        if(add) res[0] = add;
        else res.erase(res.begin());
        return res;
    }
};