class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        vector<bool> is_prime(n, true);
        for(int i = 2; i*i < n; i++){
            if(is_prime[i]){
                for(int j = i * i; j<n; j+=i){
                    is_prime[j] = false;
                }
            }
        }

        for(int i = 2; i<n; i++){
            if(is_prime[i]) count++;
        }

        return count;
    }
};