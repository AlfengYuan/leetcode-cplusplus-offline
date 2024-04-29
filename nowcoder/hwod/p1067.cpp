#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

vector<pair<int, int>> black;
vector<pair<int, int>> white;
vector<vector<int>> board;
vector<vector<int>> dir = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
int wres = 0, bres = 0;
void getAir(int x, int y) {
	bool bflag = false, wflag = false;
	for (auto& d : dir) {
		int dx = x + d[0];
		int dy = y + d[1];
		if (dx < 0 || dx >= 19 || dy < 0 || dy >= 19) continue;
		if (board[dx][dy] == 1) bflag |= true;
		if (board[dx][dy] == 2) wflag |= true;
	}

	if (bflag) bres++;
	if (wflag) wres++;
}
int main(int argc, char* argv) {
	int x, y;
	string input;
	getline(cin, input);
	stringstream ss1(input);
	while (ss1 >> x >> y) {
		black.push_back({ x, y });
		//if (cin.get() == '\n') break;
	}

	getline(cin, input);
	stringstream ss2(input);
	while (ss2 >> x >> y) {
		white.push_back({ x, y });
		//if (cin.get() == '\n') break;
	}


	board = vector<vector<int>>(19, vector<int>(19, 0));

	for (auto& b : black) {
		board[b.first][b.second] = 1;
	}

	for (auto& w : white) {
		board[w.first][w.second] = 2;
	}

	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			if (board[i][j] > 0) continue;
			getAir(i, j);
		}
	}

	cout << bres << " " << wres << endl;
	
	return 0;
}