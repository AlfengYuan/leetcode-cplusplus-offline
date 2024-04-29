#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {
    int x, y;
    vector<int> vec;
    while (cin >> x) {
        vec.push_back(x);
        //if(cin.get()=='\n') break;
    }

    //cin >> y;

    y = vec.back();
    vec.pop_back();

    int i = 0;
    for (; i < vec.size(); i++) {
        if (y <= vec[i]) {
            cout << i + 1 << endl;
            break;
        }
    }

    if(i==vec.size()) cout << vec.size() + 1 << endl;

    return 0;
}