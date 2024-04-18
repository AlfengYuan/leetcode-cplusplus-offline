class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        if(n==0) return 0;
        vector<int> vec;
        while(n){
            vec.push_back(n % 2);
            n /= 2;
        }

        for(int i = vec.size(); i < 32; i++){
            vec.push_back(0);
        }

        uint32_t res = 0;
        for(int i = 0; i<vec.size(); i++){
            res += pow(2, vec.size()-i-1) * vec[i];
        }

        return res;
    }
};