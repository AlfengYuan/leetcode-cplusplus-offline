#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]){
    int k, n, m;
    int ans = 0;
    cin >> k >> n >> m;
    //vector<int> vec;
    while(k){
        //vec.push_back(k % m);
        if(k % m == n) ans++;
        k /= m;
    }

    cout << ans << endl;


    return 0;
}