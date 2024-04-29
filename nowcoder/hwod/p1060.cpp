#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]){
    int m, n;
    cin >> m;
    vector<int> vec;
    int x;
    for(int i = 0; i<m; i++){
        cin >> x;
        vec.push_back(x);
    }

    sort(vec.begin(), vec.end());
    auto last = unique(vec.begin(), vec.end());
    vec.erase(last, vec.end());

    cin >> n;

    if(vec.size() < 2*n) cout << -1 << endl;
    else{
        int sum = 0;
        for(int i = 0; i<n; i++){
            sum += vec[i];
        }

        for(int i = vec.size()-1; i>= vec.size()-n; i--){
            sum += vec[i];
        }

        cout << sum << endl;
    }

    return 0;
}