class Solution {
public:
    int myAtoi(string s) {
        string strs = step1(s);
        int flag = 1;
        string result = "";
        int ret = 0;
        if(strs[0] != '+' && strs[0] != '-' && !isdigit(strs[0])) return 0;
        string strmin = "2147483648";
        int index = 0;
        if(strs[0] == '-') {
            flag *= -1;
            index += 1;
        }else if(strs[0] == '+'){
            index += 1;
        }

        while(index < strs.length() && isdigit(strs[index]))
        {
            result += strs[index];
            index++;
        }

        if (result == "") return 0;

        int lasti = 0;
        for(; lasti<result.length(); lasti++)
        {
            if(result[lasti] != '0') break;
        }

        if(lasti == result.length()) return 0;

        string lastresult = result.substr(lasti, result.length() - lasti + 1);
        
        if(flag == 1)
        {
            if(compare(strmin, lastresult, true)) return INT_MAX;
            for(int i = 0; i<lastresult.length(); i++)
            {
                ret *= 10;
                ret += lastresult[i] - '0';
            }
            return ret;
        }
        else if(flag == -1){
            if(compare(strmin, lastresult, true)) return INT_MIN;
            for(int i = 0; i<lastresult.length(); i++)
            {
                ret *= 10;
                ret += lastresult[i] - '0';
            }
            return ret*-1;
        }

        return 0;
    }

private:
    string step1(string s)
    {
        int left = 0, right = s.length()-1;
        while(left < s.length() && s[left] == ' ') left++;
        while(right >= 0 && s[right] == ' ') right--;
        return s.substr(left, right - left + 1);
    }

     bool compare(const std::string &str1, const std::string &str2, bool dflag)
    {
        if(str1.length() < str2.length()) return true;
        else if(str1.length() > str2.length()) return false;
        else{
           if (dflag) return str1 <= str2;
           else return str1 < str2;
        }
    }
};