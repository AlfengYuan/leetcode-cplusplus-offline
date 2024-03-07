#include <vector>
#include <iostream>
#include <string>
using namespace std;
 
// 辗转相除法求最大公约数（12和18的最大公约数：6） 
int gcd (int a, int b){
    a = (a < 0) ? (a = -a) : (a = a);
    b = (b < 0) ? (b = -b) : (b = b);
    while (b != 0){
    	int rem = a % b;
    	a = b;
    	b = rem;
	}
	return a;
}
		
// 求最小公倍数（12和18的最小公倍数：36）
int lcm (int a, int b){
	return a * b / gcd(a, b);
}
 
class Fraction{	
	public:
		int molecule;  // 分子
		int denominar; // 分母
		
		// 构造函数，参数：分子，分母（默认为1） 
		Fraction (int mo, int de = 1){
			if (mo > 0 && de < 0){		// 若负号在分母上，则移至分子上 
				mo = -mo;
				de = -de;
			}
			else if (mo < 0 && de < 0){ // 分子与分母均为负，结果得正 
				mo = -mo;
				de = -de;
			}
			else{
				mo = mo;
				de = de;
			}
			int g = gcd(mo, de);		// 求分子与分母的最大公约数 
			if (g != 0){ 				// 在约分前，先判断最大公约数是否为0 
				this->molecule = mo / g;
				this->denominar = de / g;
			}
		}
		
		// 拷贝构造函数 
		Fraction (const Fraction &F){
			int mo = F.molecule;
	    	int de = F.denominar;
	    	if (mo > 0 && de < 0){		// 若负号在分母上，则移至分子上 
				mo = -mo;
				de = -de;
			}
			else if (mo < 0 && de < 0){ // 分子与分母均为负，结果得正 
				mo = -mo;
				de = -de;
			}
			else{
				mo = mo;
				de = de;
			}
			int g = gcd(mo, de);		// 求分子与分母的最大公约数 
			if (g != 0){ 				// 在约分前，先判断最大公约数是否为0 
				this->molecule = mo / g;
				this->denominar = de / g;
			}
		}
		
		// 析构函数 
		~Fraction (){
			// 什么也不做 
		}
		
		// 重载运算符：+ 
		Fraction operator + (const Fraction &other){
			if ((this->denominar != 0) && (other.denominar != 0)){	// 判断分母是否为0 
				int de = lcm(this->denominar, other.denominar);
				int mo = (this->molecule * de / this->denominar) + (other.molecule * de / other.denominar);
				return Fraction(mo, de);
			}
			else
				return Fraction(1, 0);
		}
		
		// 重载运算符：-
		Fraction operator - (const Fraction &other){
			if ((this->denominar != 0) && (other.denominar != 0)){ // 判断分母是否为0 
				int de = lcm(this->denominar, other.denominar);
				int mo = (this->molecule * de / this->denominar) - (other.molecule * de / other.denominar);
				return Fraction(mo, de);
			}
			else
				return Fraction(1, 0);
		}
		
		// 重载运算符：*
		Fraction operator * (const Fraction &other){
			if ((this->denominar != 0) && (other.denominar != 0)){ // 判断分母是否为0 
				int de = this->denominar * other.denominar;
				int mo = this->molecule * other.molecule;
				return Fraction(mo, de);
			}
			else
				return Fraction(1, 0);
		}
		
		// 重载运算符：/
		Fraction operator / (const Fraction &other){
			if ((this->denominar != 0) && (other.denominar != 0)){ // 判断分母是否为0 
				int de = this->denominar * other.molecule;
				int mo = this->molecule * other.denominar;
				return Fraction(mo, de);
			}
			else
				return Fraction(1, 0);
		}
		
		// 重载运算符：<
		bool operator < (const Fraction &other){
			if ((this->denominar != 0) && (other.denominar != 0)){
				int l = lcm(this->denominar, other.denominar);
				int l1 = this->molecule * l / this->denominar;
				int l2 = other.molecule * l / other.denominar;
				return l1 < l2;
			}
			else
				return false;
		}
		
		// 重载运算符：>
		bool operator > (const Fraction &other){
			if ((this->denominar != 0) && (other.denominar != 0)){
				int l = lcm(this->denominar, other.denominar);
				int l1 = this->molecule * l / this->denominar;
				int l2 = other.molecule * l / other.denominar;
				return l1 > l2;
			}
			else
				return false;
		}
		
		// 重载运算符：<=
		bool operator <= (const Fraction &other){
			if ((this->denominar != 0) && (other.denominar != 0)){
				int l = lcm(this->denominar, other.denominar);
				int l1 = this->molecule * l / this->denominar;
				int l2 = other.molecule * l / other.denominar;
				return l1 <= l2;
			}
			else
				return false;
		}
		
		// 重载运算符：>=
		bool operator >= (const Fraction &other){
			if ((this->denominar != 0) && (other.denominar != 0)){
				int l = lcm(this->denominar, other.denominar);
				int l1 = this->molecule * l / this->denominar;
				int l2 = other.molecule * l / other.denominar;
				return l1 >= l2;
			}
			else
				return false;
		}
		
		// 重载运算符：==
		bool operator == (const Fraction &other){
			if ((this->denominar != 0) && (other.denominar != 0)){
				int l = lcm(this->denominar, other.denominar);
				int l1 = this->molecule * l / this->denominar;
				int l2 = other.molecule * l / other.denominar;
				return l1 == l2;
			}
			else
				return false;
		}
		
		// 重载运算符：!=
		bool operator != (const Fraction &other){
			if ((this->denominar != 0) && (other.denominar != 0)){
				int l = lcm(this->denominar, other.denominar);
				int l1 = this->molecule * l / this->denominar;
				int l2 = other.molecule * l / other.denominar;
				return l1 != l2;
			}
			else
				return false;
		}
		
		// 重载赋值运算符：=
		void operator = (const Fraction &F)
	    {
	    	int mo = F.molecule;
	    	int de = F.denominar;
	    	if (mo > 0 && de < 0){		// 若负号在分母上，则移至分子上 
				mo = -mo;
				de = -de;
			}
			else if (mo < 0 && de < 0){ // 分子与分母均为负，结果得正 
				mo = -mo;
				de = -de;
			}
			else{
				mo = mo;
				de = de;
			}
			int g = gcd(mo, de);		// 求分子与分母的最大公约数 
			if (g != 0){ 				// 在约分前，先判断最大公约数是否为0 
				this->molecule = mo / g;
				this->denominar = de / g;
			}
	    }
		
		// 重载输入流：>>
		friend std::istream &operator >> (std::istream &input, Fraction &F)
	    {
	        //input >> F.molecule >> F.denominar;
            input >> F.molecule;
            F.denominar = 1;
	        int mo = F.molecule;
	    	int de = F.denominar;
	    	if (mo > 0 && de < 0){		// 若负号在分母上，则移至分子上 
				mo = -mo;
				de = -de;
			}
			else if (mo < 0 && de < 0){ // 分子与分母均为负，结果得正 
				mo = -mo;
				de = -de;
			}
			else{
				mo = mo;
				de = de;
			}
			int g = gcd(mo, de);		// 求分子与分母的最大公约数 
			if (g != 0){ 				// 在约分前，先判断最大公约数是否为0 
				F.molecule = mo / g;
				F.denominar = de / g;
			}
	        return input;            
	    }
		
		// 重载输出流：<<
		friend std::ostream &operator << (std::ostream &output, Fraction &F)
    	{
    		if (F.denominar == 1 && F.molecule >= 0)	// 分子大于等于0，分母为1 
	        	output << F.molecule;
	        else if (F.denominar == 1 && F.molecule < 0)// 分子小于0，分母为1 
	        	//output << "(" << F.molecule << ")";
                output << F.molecule;
	        else if (F.denominar == 0)					// 分母为0 
	        	output << "ERROR";
	        else
	        	output << F.molecule << "/" << F.denominar;	
	        return output;
    	}
};
 
Fraction compute(string &s, int left, int right){
    char op = '+';
    Fraction num(0);
    vector<Fraction> st;
    for(int i = left; i<=right; i++){
        if(isdigit(s[i])) {
            Fraction a(10);
            Fraction b(s[i]-'0');
            num = num * a + b;
        }
        if(s[i] == '('){
            int layer = 0;
            int j = i;
            while(j <= right){
                if(s[j] == '('){
                    layer++;
                }else if(s[j] == ')'){
                    layer--;
                    if(layer==0) break;
                }
                j++;
            }
            num = compute(s, i+1, j-1);
            i = j+1;
        }
 
        if(!isdigit(s[i]) || i ==right){
            switch(op){
                case '+': st.push_back(num); break;
                case '-': {
                    Fraction c(0);
                    st.push_back(c-num); break;
                }
                case '*': {
                    st.back() = st.back() * num; break;
                }
                case '/': {
                    st.back() = st.back() / num; break;
                }
            }
            op = s[i];
            num = 0;
        }
    }
    Fraction res(0);
    for(Fraction x: st){
        res = res + x;
    }
 
    return res;
}
 
int main(int argc, char *argv[]){
    string s;
    while(getline(cin, s)){
        string str = "";
        for(int i = 0; i<s.length(); i++){
            if(s[i]==' ') continue;
            str += s[i];
        }
 
        Fraction result = compute(str, 0, str.length()-1);
        cout << result << endl;
    }
 
    return 0;
}

//1 + 5 * 7 / 8
//43/8

//1 / (0 - 5)
//-1/5

//1 * (3 * 4 / (8 - (7 + 0)))
//12 