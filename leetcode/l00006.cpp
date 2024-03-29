class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        string result = "";
        string strs[numRows];
        int row = 0;
        bool down = true;
        for(char &c : s)
        {
            if(row >=0 && row < numRows && down) strs[row++] += c;
            else if(row == numRows)
            {
                down = false;
                row -= 2;
                strs[row--] += c; 
            }
            else if(row >=0 && row < numRows && !down) strs[row--] += c;
            else if(row < 0)
            {
                down = true;
                row += 2;
                strs[row++] += c;
            }
        }

        for(int i = 0; i<numRows; i++)
        {
            result += strs[i];
        }

        return result;

    }
};