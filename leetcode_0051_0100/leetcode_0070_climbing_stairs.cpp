class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
        else if(n == 2) return 2;
        else if(n == 3) return 3;
        else
        {
            int first = 3, two = 2;
            for(int i = 4; i <= n; i++)
            {
                int curr = first + two;
                two = first;
                first = curr;
            }
            return first;
        }

    }
};