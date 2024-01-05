class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = static_cast<int>(height.size() - 1);
        int result = 0;
        while(left >= 0 && right >= 0 && left < right && right < height.size()){
            if(height[left] < height[right])
            {
                int curr = (right - left) * height[left];
                result = (curr > result ? curr : result);
                cout << result << endl;
                left++;
            }
            else{
                int curr = (right - left) * height[right];
                result = (curr > result ? curr : result);
                cout << result << endl;
                right--;
            }
        }

        return result;

    }
};