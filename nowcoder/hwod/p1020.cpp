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

char dec2alpha[27] = { '0', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
int main(int argc, char* argv[]) {
	string input;
	queue<int> myq;
	string res = "";
	cin >> input;

	for (int i = 0; i < input.length(); i++) {
		if (input[i] != '*') {
			myq.push(input[i] - '0');
		}
		else {
			while (myq.size() > 2) {
				res += dec2alpha[myq.front()];
				myq.pop();
			}
			int x = myq.front(); myq.pop();
			int y = myq.front(); myq.pop();
			res += dec2alpha[x * 10 + y];
		}
	}

	cout << res << endl;
	return 0;
}