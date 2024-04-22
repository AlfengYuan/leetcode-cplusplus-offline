class Solution {
    
public:
    string convertToTitle(int columnNumber) {
        string res = "";
        vector<char> mydict = {'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G',
                                'H', 'I', 'J', 'K', 'L', 'M', 'N',
                                'O', 'P', 'Q', 'R', 'S', 'T', 'U',
                                'V', 'W', 'X', 'Y'};
        while(columnNumber){
            res = mydict[columnNumber % 26] + res;
            if(columnNumber % 26 == 0){
                columnNumber--;
            }
            columnNumber /= 26;
        }

        return res;
    }
};