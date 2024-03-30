class Solution {
public:
    string multiply(string num1, string num2) {
        string result = "";
        for(int j = num2.length()-1; j >= 0; j--){
            string curr = "";
            int add = 0;
            for(int i = num1.length()-1; i >= 0; i--){
                int mul = (num1[i] - '0') * (num2[j] - '0') + add;
                curr = to_string(mul % 10) + curr;
                add = mul / 10;
            }
            if(add > 0) curr = to_string(add) + curr;
            curr = curr + string((num2.length()-j-1), '0');
            result = bigAdd(result, curr);
        }

        for(int i = 0; i < result.length(); i++){
            if(result[i] != '0') {
                return result.substr(i, result.length()-i);
            }
        }

        return "0";


    }

    string bigAdd(string str1, string str2){
        int i = str1.length() - 1;
        int j = str2.length() - 1;

        string result = "";

        int add = 0;
        while(i >= 0 || j >= 0){
            while(i >= 0 && j >= 0){
                int curr = (str1[i] - '0') + (str2[j] - '0') + add;
                result = to_string(curr % 10) + result;
                add = curr / 10;
                i--;
                j--;
            }

            while(i >= 0){
                int curr = (str1[i] - '0') + add;
                result = to_string(curr % 10) + result;
                add = curr / 10;
                i--;
            }

            while(j >= 0){
                int curr = (str2[j] - '0') + add;
                result = to_string(curr % 10) + result;
                add = curr / 10;
                j--;
            }
        }

        if(add > 0) result = to_string(add) + result;

        return result;

    }
};