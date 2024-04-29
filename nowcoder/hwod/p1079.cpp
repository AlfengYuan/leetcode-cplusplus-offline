#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main(int argc, char* argv[]) {
	string input;
	getline(cin, input);

	stringstream ss(input);
	string tmp;
	vector<int> res;
	vector<vector<int>> vec(10, vector<int>());
	
	int index = 0;
	while (getline(ss, tmp, ',')) {
		int curr = atol(tmp.c_str());
		vec[abs(curr % 10)].push_back(curr);
	}

	for (int i = 0; i < 10; i++) {
		for (int& v : vec[i]) {
			res.push_back(v);
		}
	}

	for (int i = 0; i < res.size(); i++) {
		cout << res[i];
		if (i < res.size() - 1) cout << ",";
	}
	cout << endl;

	return 0;
}