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
	string s, l;
	cin >> s;
	cin >> l;

	int start = 0;
	for (int i = 0; i < s.length(); i++) {
		int j = start;
		for (; j < l.length(); j++) {
			if (l[j] == s[i]) {
				start = j + 1;
				break;
			}
		}

		if (j == l.length()) {
			cout << -1 << endl;
			return 0;
		}
	}

	cout << start - 1 << endl;
	return 0;
}