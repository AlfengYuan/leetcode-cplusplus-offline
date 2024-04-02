class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> a(n, 1);
        for(int i = 1; i<n; i++){
            a[i] = i+1;
        }
        
        string res = "";
        if(k==1) {
            for(int &i : a){
                res += to_string(i);
            }
            return res;
        }

        for(int i = 1; i<k; i++){
            if(next_permutation(a.begin(), a.end())) continue;
            break;
        }

        for(int &i : a){
            res += to_string(i);
        }
        return res;


    }
};