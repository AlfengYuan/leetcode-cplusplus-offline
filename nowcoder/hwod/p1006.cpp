// https://codefun2000.com/d/hwod/p/P1006
#include <stack>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    string input;
    cin >> input;
    stack<char> mystack;
    int ans = 0;
    for (int i = 0; i < input.length(); i++) {
        if (input[i] == 'X') {
            if (mystack.empty()) {
                mystack.push('X');
            }
            else if (mystack.top() == 'X') {
                mystack.push('X');
            }
            else {
                mystack.pop();
                if (mystack.empty()) ans++;
            }
        }
        else {
            if (mystack.empty()) {
                mystack.push('Y');
            }
            else if (mystack.top() == 'Y') {
                mystack.push('Y');
            }
            else {
                mystack.pop();
                if (mystack.empty()) ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;

}