class Solution {
public:
    int reverse(int x) {
        int result = 0;
        string strmin = "2147483648";
        int y = x;
        if(x > 0) y *= -1;
        string str = "";
        while(y)
        {
            str += (-(y % 10) + '0');
            y /= 10;
        }
        
        if(x > 0)
        {
            if(compare(strmin, str, true)) return 0;
            for(int i = 0; i<str.length(); i++)
            {
                result *= 10;
                result += str[i] - '0';
            }
            return result;
        }
        else if(x < 0){
            if(compare(strmin, str, false)) return 0;
            for(int i = 0; i<str.length(); i++)
            {
                result *= 10;
                result += str[i] - '0';
            }
            return result*-1;
        }

        return 0;
    }

private:
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