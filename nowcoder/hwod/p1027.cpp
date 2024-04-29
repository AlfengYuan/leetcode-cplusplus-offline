#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(int argc, char *argv[]){
    vector<vector<int>> stu;
    int h, n, x;
    cin >> h >> n;
    //stu.push_back({0, h});
    for(int i = 0; i<n; i++){
        cin >> x;
        stu.push_back({abs(h-x), x});
    }

    sort(stu.begin(), stu.end(), [](vector<int> stu1, vector<int> stu2){
        if(stu1[0] != stu2[0]){
            return stu1[0] < stu2[0];
        }else{
            return stu1[1] < stu2[1];
        }
    });

    for(int i = 0; i<stu.size(); i++){
        cout << stu[i][1];
        if(i != stu.size()-1) cout << " ";
    }
    cout << endl;

    return 0;
}