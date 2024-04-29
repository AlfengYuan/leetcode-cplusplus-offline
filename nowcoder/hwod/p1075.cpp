#include <functional>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <bit>
using namespace std;

int main(int argc, char *argv[]){

    int n;
    cin >> n;
    int m = __builtin_popcount(n);
    for(long long i = n+1; i<=1e9; i++){
        if(__builtin_popcount(i) == m){
            cout << i << endl;
            break;
        }
    }
    
    return 0;
}