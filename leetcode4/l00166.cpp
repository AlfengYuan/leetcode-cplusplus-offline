class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator==0) return "0";
        if(denominator==1) return to_string(numerator);
        if(denominator==-1){
            if(numerator>0){
                return "-"+to_string(numerator);
            }else{
                string curr = to_string(numerator);
                return curr.substr(1, curr.length()-1);
            }
        }
        bool flag = false;
        long long mo = numerator;
        long long de = denominator;
        if(mo < 0){
            mo = -mo;
            flag = !flag;
        }

        if(de < 0){
            de = -de;
            flag = !flag;
        }
        unordered_map<int, int> mymap;
        string res = "";
        while(mo >= de){
            int curr = mo / de;
            res += to_string(curr);
            mo -= de * curr;
        }

        if(mo == 0) return res;
        if(res == "") res += "0";
        res += ".";

        string dec = "";
        while(mo!=0){
            if(mymap.count(mo)){
                dec.insert(mymap[mo], "(");
                dec.push_back(')');
                break;
            }
            mymap[mo] = dec.length();
            mo *= 10;
            int curr = mo / de;
            dec += to_string(curr);
            mo -= de * curr;
        }

        if(flag) return "-"+res+dec;
        return res+dec;

        

    }
};