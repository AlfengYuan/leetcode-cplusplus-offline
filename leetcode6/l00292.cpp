// class Solution {
// public:
//     bool canWinNim(int n) {
//         if(n < 4) return true;
//         return !canWinNim(n-1) || !canWinNim(n-2) || !canWinNim(n-3);
//     }
// };
class Solution {
public:
    bool canWinNim(int n) {
        return n%4!=0;

    }
};