#include <vector>
#include <iostream>
#include <string>
#include <iostream>
using namespace std;
int w, h, y, x, sy, sx, t;
vector<string> board;
int res = 0;
int main(int argc, char *argv[]){
    string tmp;
    cin >> w >> h >> y >> x >> sy >> sx >> t;
    cin.get();
    while(cin >> tmp){
        board.push_back(tmp);
        if(board.size() == h) break;
    }

    if(board[x][y] == '1') res++;

    for(int i = 0; i<t; i++){
        int new_x = x + sx; 
        int new_y = y + sy;
        if(new_x>=0 && new_x < h && new_y >=0 && new_y < w){
            if(board[new_x][new_y] == '1') res++;
            x = new_x, y = new_y;
        }else{
            if(new_x < 0 || new_x >= h) sx = -sx;
            if(new_y < 0 || new_y >= w) sy = -sy;
            i--;
        }

    }

    cout << res << endl;

    return 0;
}