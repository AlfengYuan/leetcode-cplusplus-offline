#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[]){
    string input;
    cin >> input;
    vector<string> vec;
    for(int i = 0; i<input.length(); i++){
        int left = i;
        while(left < input.length() && input[left] != ',') left++;
        vec.push_back(input.substr(i, 6));
        i = left;
    }

    sort(vec.begin(), vec.end());

    for(int i = 0; i<vec.size(); i++){
        cout << vec[i];
        if(i != vec.size()-1) cout << ",";
    }

    cout << endl;
    return 0;
}