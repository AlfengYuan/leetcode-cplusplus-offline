class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        if (s.length() <= 1) return s.length();

        int *fn = new int[s.length()];
        int ascii[128] = {0};
        fn[0] = 1;
        int left, right;
        for(right = 1; right < s.length(); right++)
        {
            ascii[static_cast<int>(s[right])] += 1;
            for(left = right - 1; (left >= 0 && ascii[static_cast<int>(s[left])] == 0); left--)
            {
                ascii[static_cast<int>(s[left])] += 1;
            }

            fn[right] = max({fn[right - 1], (right-left)});

            for(int i = 0; i<128; i++)
            {
                ascii[i] = 0;
            }
        }

        int result = fn[s.length() - 1];
        delete []fn;
        return result;
      

    }
};