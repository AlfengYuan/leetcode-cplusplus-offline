#include <vector>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]){
    int wa, wb, wt, pa, pb;
    cin >> wa >> wb >> wt >> pa >> pb;
    int totalA = (wt - wb) / wa;

    int res = 0;
    for(int i = 1; i<=totalA; i++){
        int j = (wt - wa * i) / wb;
        if(wb * j + wa * i == wt){
            int curr = pa * i + pb * j;
            res = max(res, curr);
        }
    }

    cout << res << endl;

    return 0;


}