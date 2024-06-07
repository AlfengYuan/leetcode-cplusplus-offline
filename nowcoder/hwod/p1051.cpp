#include <vector>
#include <iostream>
#include <string>
#include <numeric>
#include <iomanip>
#include <algorithm>
#include <climits>
using namespace std;


int main(int argc, char *argv[]){
    int x, y;
    vector<pair<int, int>> vec;

    while(cin >> x >> y){
        vec.push_back({x, y});
        if(cin.get() == '\n') break;
    }

    double k1 = INT_MAX, k2 = INT_MAX;

    cout << vec[0].first << " " << vec[0].second << " ";
    for(int i = 1; i<vec.size()-1; i++){
        if(i==1 && vec[i].first != vec[i-1].first){
            k1 = (double)(vec[i].second - vec[i-1].second) / (double)(vec[i].first - vec[i-1].first);
        }else{
            k1 = k2;
        }

        if(vec[i].first != vec[i+1].first){
            k2 = (double)(vec[i+1].second - vec[i].second) / (double)(vec[i+1].first - vec[i].first);
        }else{
            k2 = INT_MAX;
        }

        if(k1 != k2){
            cout << vec[i].first << " " << vec[i].second << " ";
        }
    }

    if(vec.size() > 1){
        cout << vec[vec.size()-1].first << " " << vec[vec.size()-1].second << endl;
    }


    return 0;
}