// https://codefun2000.com/d/hwod/p/P1001
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]){
    string input;
    cin >> input;
    string pre = "";
    string suf = "";
    int left = 0;
    for(; left<input.length(); left++){
        if(input[left] == ',') break;
    }
    pre = input.substr(0, left);
    suf = input.substr(left+1, input.length()-left-1);
    
    if(pre.empty()) pre.push_back('/');
    if(suf.empty()) suf.push_back('/');
    if(pre.back() != '/') pre.push_back('/');
    if(suf.front() != '/') suf = '/' + suf;

    if(pre.back()=='/' && suf.front()=='/') pre.pop_back();

    cout << pre + suf << endl;

    return 0;


}