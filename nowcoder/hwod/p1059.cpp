#include <filesystem>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<int> vec;
vector<int> a;
vector<int> b;

void compare(){
    int cnt = 0;
    for(int i = 0; i<a.size(); i++){
        if(a[i] > b[i]) cnt++;
    }
    vec[cnt]++;
}

int main(int argc, char *argv[]){
    int x;
    while(cin >> x){
        vec.push_back(x);
    }
    a.assign(vec.begin(), vec.begin()+vec.size() / 2);
    b.assign(vec.begin()+vec.size()/2, vec.end());
    vec.clear();
    vec.resize(a.size()+1, 0);

    sort(a.begin(), a.end());

    do{
        compare();
    }while(next_permutation(a.begin(), a.end()));

    int res = 0;

    for(int i = vec.size()-1; i>=0; i--){
        if(vec[i]>0){
            cout << vec[i] << endl;
            return 0;
        }
    }

    cout << 1 << endl;

    return 0;
}