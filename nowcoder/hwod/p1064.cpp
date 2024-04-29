#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(int argc, char* argv[]) {
    int m, n, x;
    cin >> m >> n;
    map<int, vector<pair<int, int>>> mymap;
    int res = 0;
    //vector<vector<int>> vec(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> x;
            //vec[m][n] = x;
            if (x > 0) {
                if (mymap.count(x) != 0) {
                    mymap[x][0].first = min(mymap[x][0].first, i);
                    mymap[x][1].first = max(mymap[x][1].first, i);
                    mymap[x][0].second = min(mymap[x][0].second, j);
                    mymap[x][1].second = max(mymap[x][1].second, j);
                }
                else {
                    mymap[x] = { {i, j}, {i, j} };
                }
            }
        }
    }

    for (auto& m : mymap) {
        res = max(res, (m.second[1].first - m.second[0].first + 1)
            * (m.second[1].second - m.second[0].second + 1));
    }

    cout << res << endl;
    return 0;
}