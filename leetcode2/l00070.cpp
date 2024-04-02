class Solution {
public:
    int climbStairs(int n) {
        if(n==1) return 1;
        else if(n==2) return 2;
        
        int one = 1, two = 2;
        int res;
        for(int i = 3; i<=n; i++){
            res = one + two;
            one = two;
            two = res;
        }
        return res;
    }
};