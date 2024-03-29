class Solution {
public:
    string intToRoman(int num) {
        string result = "";
        if(num >= 1000)
        {
            result += string(num / 1000, 'M');
            num %= 1000;
        }
        if(num >= 900){
            result += "CM";
            num -= 900;
        } 
        if(num >= 500){
            result += "D";
            num -= 500;
        }
        if(num >= 400){
            result += "CD";
            num -= 400;
        }
        if(num >= 100){
            result += string(num / 100, 'C');
            num %= 100;
        }
        if(num >= 90){
            result += "XC";
            num -= 90;
        }
        if(num >= 50){
            result += "L";
            num -= 50;
        }
        if(num >= 40){
            result += "XL";
            num -= 40;
        }
        if(num >= 10){
            result += string(num / 10, 'X');
            num %= 10;
        }
        if(num >= 9){
            result += "IX";
            num -= 9;
        }
        if(num >= 5){
            result += "V";
            num -= 5;
        }
        if(num >= 4){
            result += "IV";
            num -= 4;
        }
        if(num >= 1){
            result += string(num, 'I');
            num %= 1;
        }



        return result;

    }
};