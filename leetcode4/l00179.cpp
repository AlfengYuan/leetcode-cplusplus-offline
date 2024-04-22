class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int &a, int &b){
            string c = to_string(a) + to_string(b);
            string d = to_string(b) + to_string(a);
            return c > d;
        });

        string res = "";
        for(int &x: nums){
            res += to_string(x);
        }
        if(res.length() > 1 && res[0] == '0' && res[res.length()-1] == '0') return "0";
        return res;
    }
};