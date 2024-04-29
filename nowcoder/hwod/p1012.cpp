#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int main(int argc, char *argv[]){
    string input;
    cin >> input;
    input += '0';
    stack<char> mystack;
    int ans = 0;

    for(int i = 0; i<input.length(); i++){
        if(input[i] == '0'){
            while(mystack.size() >= 3){
                mystack.pop();mystack.pop(); mystack.pop();
                ans++;
            }
            while(mystack.size() >= 2){
                mystack.pop();mystack.pop();
                ans++;
            }
            while(mystack.size() >= 1){
                mystack.pop();
                ans++;
            }

        }else if(input[i] == '1'){
            mystack.push('1');
        }
    }

    cout << ans << endl;

    return 0;

}