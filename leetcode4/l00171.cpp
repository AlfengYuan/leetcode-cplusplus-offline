class Solution {
public:
    int titleToNumber(string columnTitle) {
        int len = columnTitle.length() - 1;
        int res = 0;
        for (int i = 0; i < columnTitle.length(); i++) {
            res += (columnTitle[i] - 'A' + 1) * pow(26, len - i);
        }

        return res;

    }
};