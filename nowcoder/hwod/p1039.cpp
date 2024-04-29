#include <functional>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> vec(26, 0);
int main(int argc, char *argv[]){
    string input;
    int k;
    getline(cin, input);
    cin >> k;
    for(int i = 0; i<input.length(); i++){
        int j = i;
        while(input[j] == input[i]) j++;
        vec[input[i]-'A'] = max(vec[input[i]-'A'], j-i);
        i = j-1;
    }
    sort(vec.begin(), vec.end(), greater<int>());

    if(k < 0 || k >= vec.size()) cout << -1 << endl;
    else if(vec[k-1] == 0) cout << -1 << endl;
    else{
        cout << vec[k-1] << endl;
    }

    return 0;

}