class Solution {
public:
    bool isValid(string s) {
        stack<char> mystack;
        for(char &c : s)
        {
            if(c == '(' || c == '[' || c=='{')
            {
                mystack.push(c);
            }
            else{
                if(mystack.empty()) return false;
                char topv = mystack.top();
                if(c==')')
                {
                    if(topv == '(')
                    {
                        mystack.pop();
                    }else{
                        return false;
                    }
                } else if( c == ']')
                {
                    if(topv == '[') mystack.pop();
                    else return false;
                }
                else if( c == '}')
                {
                    if(topv == '{') mystack.pop();
                    else return false;
                }
            }
        }

        if (mystack.empty()) return true;
        return false;
    }
};