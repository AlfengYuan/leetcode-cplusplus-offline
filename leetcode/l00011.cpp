class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int res = 0;
        while(left < right){
            int curr = min(height[left], height[right]) * (right - left);
            res = max(res, curr);
            if(height[left] < height[right]){
                left++;
            }else{
                right--;
            }
        }

        return res;
    }
};