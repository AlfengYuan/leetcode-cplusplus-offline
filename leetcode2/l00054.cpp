class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int n = rows * cols;

        vector<int> res;
        int x = 0, y = 0;
        int circle = 0;
        int count = 0;
        while (count < n) {
            while(count < n && y < cols - circle) {
                res.push_back(matrix[x][y++]);
                count++;
            }
            y--; x++;

            while(count < n && x < rows-circle) {
                res.push_back(matrix[x++][y]);
                count++;
            }
            x--; y--;

            while (count < n && y >= circle) {
                res.push_back(matrix[x][y--]);
                count++;
            }
            y++, x--;

            while (count < n && x > circle) {
                res.push_back(matrix[x--][y]);
                count++;
            }
            x++, y++;

            circle++;

        }

        return res;
    }
};