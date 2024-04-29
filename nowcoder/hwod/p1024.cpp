#include <string>
#include <vector>
#include <iostream>
using namespace std;
int main(int argc, char* argv[]) {
    string input;
    cin >> input;

    int res = 0;

    for (int i = 0; i < input.length(); i++) {
        bool left = ((i == 0) || (i > 0 && input[i - 1] == '0'));
        bool right = ((i == input.length() - 1) || ((i < input.length() - 1) && input[i + 1] == '0'));
        if (left && right && input[i] == '0') {
            res++;
            input[i] = '1';
        }
    }

    cout << res << endl;

    return 0;
}