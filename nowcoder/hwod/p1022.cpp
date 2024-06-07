#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> vec;
    int temp;
    while (cin >> temp) {
        vec.push_back(temp);
        if (cin.get() == '\n')
            break;
    }
    int len = 0;
	vector<vector<int> > res;
	int m = vec.size();
	for (int i = 0; i < m; i++) {
		int sum = 0;
		for (int j = i; j < m; j++) {
			sum += vec[j];
			if (sum <= n * (j - i + 1)) {
				if (len < j - i + 1) {
					len = j - i + 1;
					res.clear();
				}
				if (len == j - i + 1)
					res.push_back({ i,j });
			}
		}
	}
    int k = res.size();
	for (int i = 0; i < k; i++) {
		if (i != k - 1)
			cout << res[i][0] << "-" << res[i][1] << " ";
		else
			cout << res[i][0] << "-" << res[i][1];
	}
	return 0;
}