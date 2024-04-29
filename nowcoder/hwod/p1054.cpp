#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;


int main(int argc, char *argv[]){
    int n, x, y;
    cin >> n;
    if(n <= 1){
        cin >> x;
        cout << x <<endl;
        return 0;
    }
    vector<int> vec(n+1, 0);
    vector<int> fut(n+1, 0);

    for(int i = 0; i<n; i++){
        cin >> x;
        fut[i+1] = x;
    }

    for(int i = 0; i<n-1; i++){
        cin >> x >> y;
        if(vec[x] == 0){
            vec[x] += fut[x];
        }
        vec[x] += fut[y];
    }

    cout << *max_element(vec.begin(), vec.end()) << endl;
    return 0;
}