class Solution {
public:
    int calculate(string s) {
        string str = "";
        for(int i = 0; i<s.length(); i++){
            if(s[i] == ' ') continue;
            str += s[i];
        }

        return compute(str, 0, str.length()-1);
    }

    int compute(string &str, int left, int right){
        int num = 0;
        vector<int> vec;
        char op = '+';
        for(int i = left; i<=right; i++){
            if(isdigit(str[i])){
                num = num * 10 + (str[i] - '0');
            }

            if(str[i] == '('){
                int j = i;
                int layer = 0;
                while(j<=right){
                    if(str[j] == '(') layer++;
                    else if(str[j] == ')'){
                        layer--;
                        if(layer == 0) break;
                    }
                    j++;
                }
                num = compute(str, i+1, j-1);
                i = j+1;
            }

            if(!isdigit(str[i]) || i==right){
                switch(op){
                    case '+': vec.push_back(num); break;
                    case '-': vec.push_back(-num); break;
                    case '*': vec.back() *= num; break;
                    case '/': vec.back() /= num; break;
                }
                op = str[i];
                num = 0;
            }
        }

        int res = 0;
        for(int &v: vec){
            res += v;
        }

        return res;
    }
};