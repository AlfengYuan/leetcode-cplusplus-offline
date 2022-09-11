class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() <= 1) return intervals;
        vector<vector<int>> result;
        vector<int> first, second;    

        for(int i = 0; i<intervals.size(); i++)
        {
            first.push_back(intervals[i][0]);
            second.push_back(intervals[i][1]);
        }

        sort(first.begin(), first.end(), std::less<int>());
        sort(second.begin(), second.end(), std::less<int>());

        vector<int> tmp(2, 0);
        tmp[0] = first[0];
        for(int i = 1; i<intervals.size(); i++)
        {
            if(first[i] > second[i-1])
            {
                tmp[1] = second[i-1];
                result.push_back(tmp);
                tmp[0] = first[i];
            }

            if(i == intervals.size() - 1)
            {
                tmp[1] = second[i];
                result.push_back(tmp);
            }
        }
        return result;
    }
};