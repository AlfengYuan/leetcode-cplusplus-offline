class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        return merge(intervals);
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<int> x;
        vector<int> y;
        for(auto &v: intervals){
            x.push_back(v[0]);
            y.push_back(v[1]);
        }
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());

        vector<vector<int>> res;

        for(int i = 0; i<x.size(); i++){
            vector<int> tmp = {x[i], y[i]};
            int j = i+1;
            while(j < x.size() && x[j] <= y[j-1]) j++;
            tmp[1] = y[j-1];
            res.push_back(tmp);
            i = j-1; 
        }

        return res;
    }
};