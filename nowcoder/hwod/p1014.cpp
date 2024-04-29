#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool isy(char c) {
	return (tolower(c) == 'a' || tolower(c) == 'o' || tolower(c) == 'e' || tolower(c) == 'i' || tolower(c) == 'u');
}

int main(int argc, char* argv[]) {
	int flaw;
	string input;
	cin >> flaw >> input;

	vector<bool> flag(input.length(), false);
	for (int i = 0; i < input.length(); i++) {
		if (isy(input[i])) flag[i] = true;
	}

	int left = 0, right = 0;

	int cnt = 0;
	int res = 0;
	while (right < input.length() && left <= right) {
		if (!flag[right]) {
			cnt++;
		}
		else {
			while (cnt > flaw || !flag[left]) {
				if (!flag[left]) {
					cnt--;
				}
				left++;
			}

			if (cnt == flaw) {
				res = max(res, right - left + 1);
			}
		
		}
		right++;
	}

	cout << res << endl;

	return 0;
}