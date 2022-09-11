class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.size() <= 0) return {newInterval};
        vector<vector<int>> result;
        vector<int> first, second;    
        vector<bool> flag(2, false);

        for(int i = 0; i<intervals.size(); i++)
        {
            if(!flag[0] && intervals[i][0] > newInterval[0])
            {
                flag[0] = true;
                first.push_back(newInterval[0]);
            }
            first.push_back(intervals[i][0]);

            if(!flag[1] && intervals[i][1] > newInterval[1])
            {
                flag[1] = true;
                second.push_back(newInterval[1]);
            }
            second.push_back(intervals[i][1]);
        }

        if(!flag[0]) first.push_back(newInterval[0]);
        if(!flag[1]) second.push_back(newInterval[1]);

        // sort(first.begin(), first.end(), std::less<int>());
        // sort(second.begin(), second.end(), std::less<int>());

        vector<int> tmp(2, 0);
        tmp[0] = first[0];
        for(int i = 1; i<first.size(); i++)
        {
            if(first[i] > second[i-1])
            {
                tmp[1] = second[i-1];
                result.push_back(tmp);
                tmp[0] = first[i];
            }

            if(i == first.size() - 1)
            {
                tmp[1] = second[i];
                result.push_back(tmp);
            }
        }
        return result;
    }
};