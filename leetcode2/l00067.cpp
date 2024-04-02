class Solution {
public:
    string addBinary(string a, string b) {
        int aL = a.length() - 1;
        int bL = b.length() - 1;
        string res = "";
        int add = 0;
        while (aL>=0 || bL>=0) {
            while (aL>=0 && bL>=0) {
                int curr = a[aL] - '0' + b[bL] - '0' + add;
                res = to_string(curr % 2) + res;
                add = curr / 2;
                aL--;
                bL--;
            }

            while (aL>=0) {
                int curr = a[aL] - '0' + add;
                res = to_string(curr % 2) + res;
                add = curr / 2;
                aL--;
            }

            while (bL>=0) {
                int curr = b[bL] - '0' + add;
                res = to_string(curr % 2) + res;
                add = curr / 2;
                bL--;
            }
        }

        if (add > 0) res = to_string(add) + res;

        return res;
    }
};