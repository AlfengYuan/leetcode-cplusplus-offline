class Solution {
public:
    bool isHappy(int n) {
        if(n==1) return true;
        unordered_map<int, int> mymap;
        while(mymap.count(n) == 0){
            mymap[n] = 1;
            int cur = 0;
            while(n){
                int next = n % 10;
                cur += next * next;
                n /= 10;
            }
            if(cur == 1) return true;
            n = cur;
        }

        return false;
    }
};