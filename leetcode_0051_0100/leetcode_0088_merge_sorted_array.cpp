class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0, j = 0;
        vector<int> tmp(m+n, 0);
        while(i < m || j < n)
        {
            while(i < m && j < n)
            {
                if(nums1[i] <= nums2[j])
                {
                    tmp[i+j] = nums1[i];
                    i++;
                }
                else
                {
                    tmp[i+j] = nums2[j];
                    j++;
                }
            }

            while(i < m)
            {
                tmp[i+j] = nums1[i];
                i++;
            }

            while(j < n)
            {
                tmp[i+j] = nums2[j];
                j++;
            }
        }

        if(nums1.size() >= nums2.size())
        {
            for(int k = 0; k<i+j; k++)
            {
                nums1[k] = tmp[k];
            }
        }
        else
        {
            for(int k = 0; k<i+j; k++)
            {
                nums2[k] = tmp[k];
            }
        }

    }
};