//https://leetcode.cn/problems/range-sum-query-2d-immutable/description/
struct points{
    int l, t, r, b;
    struct Hash {
        std::size_t operator()(const points& k) const {
            return std::hash<int>()(k.l) ^ std::hash<int>()(k.t) ^ std::hash<int>()(k.r) ^ std::hash<int>()(k.b);
        }
    };
 
    // 必须提供一个等价比较函数
    struct KeyEqual {
        bool operator()(const points& lhs, const points& rhs) const {
            return lhs.l==rhs.l && lhs.t==rhs.t && lhs.r==rhs.r && lhs.b==rhs.b;
        }
    };
};

class NumMatrix {
    vector<vector<int>> myvec;
    unordered_map<points, int, points::Hash, points::KeyEqual> mymap;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        myvec = vector<vector<int>>(m, vector<int>(n, 0));
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                myvec[i][j] = matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int res = 0;
        points s;
        s.l = col1, s.t = row1, s.r = col2, s.b = row2;
        if(mymap.count(s) > 0) return mymap[s];
        
        for(int i = row1; i <= row2; i++){
            for(int j = col1; j<=col2; j++){
                res += myvec[i][j];
            }
        }
        mymap[s] = res;
        return res;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */