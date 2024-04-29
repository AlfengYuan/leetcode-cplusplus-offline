#include <vector>
#include <string>
#include <iostream>
#include <cmath>

using namespace std;
int main(int argc, char *argv[]){
    int n, e;
    cin >> n >> e;
    int y=0, last_x=0;
    long long area = 0;
    int x, h;
    for(int i = 0; i<n; i++){
        cin >> x >> h;
        area += (x - last_x) * abs(y);
        y += h;
        last_x = x;
    }

    area += (e-last_x) * abs(y);

    cout << area << endl;

    return 0;
}