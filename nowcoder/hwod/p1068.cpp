#include <iostream>
#include <vector>
#include <sstream>
#include <numeric>

using namespace std;

int main(int argc, char* argv[]) {
    string input;
    getline(cin, input);
    stringstream ss(input);
    string tmp;
    vector<int> vec;
    
    while (getline(ss, tmp, ',')) {
        vec.push_back(atol(tmp.c_str()));
    }

    //vector<bool> d(vec.size(), true);

    int jump, left;
    cin >> jump;
    cin >> left;

    int start = 0;
    while (vec.size() > left) {
        start = (start + jump + 1) % vec.size();
        //cout << vec[start] << ",";
        vec.erase(vec.begin() + start);
        start--;
    }

    //int res = 0;
    //for (int i = 0; i < vec.size(); i++) {
    //    if (d[i]) res += vec[i];
    //}

    cout << accumulate(vec.begin(), vec.end(), 0) << endl;

    return 0;
}