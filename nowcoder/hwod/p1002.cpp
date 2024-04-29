// https://codefun2000.com/d/hwod/p/P1002
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
    int n;
    cin >> n;
    int m;
    string pat;
    string input;
    vector<vector<string>> vec;
    for (int i = 1; i <= n; i++) {
        cin >> input;
        stringstream ss(input);
        string tmp;
        vector<string> vecTmp;
        while (getline(ss, tmp, '/')) {
            vecTmp.push_back(tmp);
        }
        vec.push_back(vecTmp);
    }

    cin >> m >> pat;

    int ans = 0;

    for (int i = 0; i < vec.size(); i++) {
        if (m < vec[i].size() && vec[i][m] == pat) ans++;
    }

    cout << ans << endl;

    return 0;

}