#include <vector>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
	int n, lucky;
	cin >> n;
	cin >> lucky;
	int x;
	int res = 0;
	int maxRes = 0;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x == lucky) {
			if (x < 0) {
				x--;
			}
			else {
				x++;
			}
		}
		res += x;
		maxRes = max(res, maxRes);
	}

	cout << maxRes << endl;


	return 0;
}