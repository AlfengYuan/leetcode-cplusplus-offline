#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <cstring>
#include <stack>
#include <queue>
using namespace std;

int main(int argc, char* argv[]) {
	string input;
	cin >> input;

	long long res = 0;
	for (int i = 0; i < input.length(); i++) {
		if (input[i] != '-') {
			if (isdigit(input[i])) {
				res += input[i] - '0';
			}
		}
		else {
			int j = i + 1;
			while (j < input.length() && isdigit(input[j])) j++;
			res -= atol(input.substr(i + 1, j - i - 1).c_str());
			i = j - 1;
		}
	}

	cout << res << endl;

	return 0;
}