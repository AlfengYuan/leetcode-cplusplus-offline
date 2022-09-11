class Solution {
public:
    string addBinary(string a, string b) {
        int maxLen = b.length(), minLen = a.length();
        if(a.length() > b.length())
        {
            maxLen = a.length();
            minLen = b.length();
        } 

        string result = "";
        int add = 0;
        int i = maxLen - 1, j = minLen - 1;
        for(; i >= 0 && j >= 0; i--, j--)
        {
            int aValue, bValue;
            if(a.length() > b.length())
            {
                aValue = a[i] - '0';
                bValue = b[j] - '0';
            }
            else
            {
                aValue = b[i] - '0';
                bValue = a[j] - '0';
            }

            int curr = aValue + bValue + add;
            result = to_string(curr % 2) + result;
            add = curr / 2;
        }

        if(a.length() > b.length())
        {
            while(i >= 0)
            {
                int curr = a[i] - '0' + add;
                result = to_string(curr % 2) + result;
                add = curr / 2;
                i--;
            }
        }
        else if(b.length() > a.length())
        {
            while(i >= 0)
            {
                int curr = b[i] - '0' + add;
                result = to_string(curr % 2) + result;
                add = curr / 2;
                i--;
            }
        }

        if(add) result = to_string(add) + result;

        return result;

    }
};