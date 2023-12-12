class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        size_t len1 = nums1.size(), len2 = nums2.size();
        size_t len = len1 + len2;
        size_t media = len / 2;

        int left, right = 0;

        for(int i = 0, j = 0, k = 0; (i<nums1.size() || j < nums2.size()) && (i+j <= media); )
        {
            left = right;
            if(i < nums1.size() && j < nums2.size())
            {
                right = nums1[i] < nums2[j] ? nums1[i++] : nums2[j++];
            }
            else if(i < nums1.size()) right = nums1[i++];
            else right = nums2[j++];
        }

        if (len % 2 == 0) return double((left + right) / 2.);
        else return right;

    }
};