class Solution {
public:
    int strStr(string haystack, string needle) {
        int nLen = needle.length();
        if (haystack.length() < nLen) return -1;
        for(int i = 0; i<=haystack.length()-nLen; i++){
            string curr = haystack.substr(i, nLen);
            if (curr == needle) return i;
        }

        return -1;

    }
};