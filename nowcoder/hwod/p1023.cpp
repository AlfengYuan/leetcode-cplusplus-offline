#include <iostream>
#include <vector>
#include <sstream>
#include <numeric>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {
    vector<string> vecA;
    vector<string> vecB;
    vector<string> vecC;

    string use, punch;
    while (cin >> use >> punch) {
        if (punch == "A") {
            vecA.push_back(use);
        }
        else if (punch == "B") {
            vecB.push_back(use);
        }
        else if (punch == "C") {
            vecC.push_back(use);
        }
    }

    if (vecA.size() > 0 && vecB.size() > 0 && vecC.size() > 0) {
        cout << "NULL" << endl;
    }
    else if (vecA.size() > 0 && vecB.size() > 0 && vecC.size() == 0) {
        sort(vecA.begin(), vecA.end());
        for (string& s : vecA) {
            cout << s << endl;
        }
    }
    else if (vecA.size() > 0 && vecB.size() == 0 && vecC.size() > 0) {
        sort(vecC.begin(), vecC.end());
        for (string& s : vecC) {
            cout << s << endl;
        }
    }
    else if (vecA.size() == 0 && vecB.size() > 0 && vecC.size() > 0) {
        sort(vecB.begin(), vecB.end());
        for (string& s : vecB) {
            cout << s << endl;
        }
    }
    else{
        cout << "NULL" << endl;
    }

    return 0;
}