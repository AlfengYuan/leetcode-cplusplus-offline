class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> mystack;
        for(string &s: tokens){
            if(s=="+" || s=="-" || s=="*" || s=="/"){
                int num1 = mystack.top(); mystack.pop();
                int num2 = mystack.top(); mystack.pop();
                if(s=="+"){
                    mystack.push(num2+num1);
                }else if(s=="-"){
                    mystack.push(num2-num1);
                }else if(s=="*"){
                    mystack.push(num2*num1);
                }else if(s=="/"){
                    mystack.push(num2/num1);
                }
            }else{
                mystack.push(atol(s.c_str()));
            }
        }
        return mystack.top();
    }
};