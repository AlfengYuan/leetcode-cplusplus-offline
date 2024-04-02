class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i = 0; i<n; i++){
            int j = 0;
            while(j < m+i && nums1[j] <= nums2[i]) j++;
            //nums1.insert(nums1.begin() + j, nums2[i]);
            for(int x = m+i; x>j; x--){
                nums1[x] = nums1[x-1];
            }
            nums1[j] = nums2[i];
        }
    }
};