
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> midIndex;
        size_t totalSize = nums1.size() + nums2.size();
        vector<int> res;
        midIndex.push_back(totalSize / 2);
        if (totalSize % 2 == 0)
        {
            midIndex.push_back(totalSize / 2 - 1);
        }

        size_t i = 0, j = 0;
        while(res.size() < midIndex[0] + 1 && (i < nums1.size() || j < nums2.size()))
        {
            while(res.size() < midIndex[0] + 1 && i < nums1.size() &&  j < nums2.size())
            {
                if(nums1[i] <= nums2[j])
                {
                    res.push_back(nums1[i]);
                    i++;
                }
                else
                {
                    res.push_back(nums2[j]);
                    j++;
                }
            }

            while(res.size() < midIndex[0] + 1 && i < nums1.size())
            {
                res.push_back(nums1[i]);
                i++;
            }

            while(res.size() < midIndex[0] + 1 && j < nums2.size())
            {
                res.push_back(nums2[j]);
                j++;
            }

        }

        if (totalSize % 2 == 0)
        {
            return (res[midIndex[0]] + res[midIndex[1]]) / 2.;
        }
        return res[midIndex[0]];
    }
};

int main()
{
    vector<int> nums1 = {2};
    vector<int> nums2 = {1, 3};
    Solution solution = Solution();
    double res = solution.findMedianSortedArrays(nums1, nums2);
    cout << res << endl;
    return 0;
}