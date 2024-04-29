#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;
vector<char> vec;
vector<bool> used;
vector<string> all;
bool check(string str) {
    int hours = (str[0]-'0') * 10 + (str[1] - '0');
    int mins = (str[2]-'0') * 10 + (str[3]-'0');
    if (hours > 23 || mins > 59) return false;
    return true;
}
void dfs(int cnt, string curr) {
    if (cnt == vec.size()) {
        if (check(curr)) all.push_back(curr);
        return;
    }

    for (int i = 0; i < vec.size(); i++) {
       // if (used[i] || (i > 0 && vec[i]==vec[i-1] && used[i-1])) continue;
       // used[i] = true;
        dfs(cnt + 1, curr + vec[i]);
       // used[i] = false;
    }
}

int main(int argc, char* argv[]) {
    string input;
    cin >> input;
    string pat = "";

    for (char& c : input) {
        if (c == ':') continue;
        vec.push_back(c);
        pat += c;
    }

    //used = vector<bool>(vec.size(), false);

    //sort(vec.begin(), vec.end());

    dfs(0, "");

    sort(all.begin(), all.end());
    string res = "";

    for (int i = 0; i < all.size(); i++) {
        if (all[i] == pat) {
            if (i < all.size() - 1) {
                res = all[i + 1];
            }
            else {
                res = all[0];
            }
        }
    }

    res.insert(2, ":");

    cout << res << endl;


    return 0;
}