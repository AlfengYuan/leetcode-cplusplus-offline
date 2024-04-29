#include <unordered_map>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[]){
    string input;
    cin >> input;
    int k;
    cin >> k;
    vector<int> vec(52, -1);
    for(int i = 0; i<input.length(); i++){
        if(input[i] >= 'A' && input[i] <= 'Z'){
            if(vec[input[i]-'A'] == -1){
                vec[input[i]-'A'] = i;
            }
        }else{
            if(vec[input[i]-'a'+26] == -1){
                vec[input[i]-'a'+26] = i;
            }
        }
    }

    sort(input.begin(), input.end());

    if(k > input.length()) k = input.length();
    char c = input[k-1];

    if(c >= 'A' && c <= 'Z'){
        cout << vec[c-'A'] << endl;
    }else{
        cout << vec[c-'a'+26] << endl;
    }
    
    return 0;
}