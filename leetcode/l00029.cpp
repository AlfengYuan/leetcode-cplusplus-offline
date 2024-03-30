class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend==0) return 0;
        else if (dividend == divisor) return 1;
        else if (divisor == 1) return dividend;
        else if (divisor == INT_MIN) return 0;
        else if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        else if (divisor == -1) return -dividend;
        else {
            int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
            if(dividend > 0) dividend = -dividend;
            if(divisor < 0) divisor = -divisor;
            int result = 0;
            while(dividend <= 0){
                dividend += divisor;
                result += 1;
            }

            return (result-1)*sign;
        }
    }
};