#include <cctype>
#include<iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

bool check(string &str){
    if(str.length() < 8) return false;
    int uper=0, low=0, digit=0;
    for(int i = 0; i<str.length(); i++){
        if(isdigit(str[i])){
            digit++;
        }else if(str[i] >= 'A' && str[i] <= 'Z'){
            uper++;
        }else if(str[i] >= 'a' && str[i] <= 'z'){
            low++;
        }
    }
    if(uper==0 || low==0 || digit==0) return false;
    if(uper+low+digit == str.length()) return false;

    return true;
}

int main(int argc, char *argv[]){
    string input;
    getline(cin, input);
    string str = "";
    for(int i = 0; i<input.length(); i++){
        if(input[i] == '<'){
            if(str.length() > 0) str.pop_back();
        }else{
            str += input[i];
        }
    }

    cout << str << ",";
    if(check(str)) {
        cout << "true" << endl;
    }else{
        cout << "false" << endl;
    }

    return 0;
}