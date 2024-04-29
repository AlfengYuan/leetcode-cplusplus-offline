#include <cctype>
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char *argv[]){
    string input;
    cin >> input;
    vector<int> nums;
    int res = 0;
    for(int i = 0; i<input.length(); i++){
        if(isdigit(input[i])){
            int j = i;
            while(j< input.length() && isdigit(input[j])) j++;
            nums.push_back(atol(input.substr(i, j-i).c_str()));
            i = j;
        }
    }

    for(int i = 0; i<nums.size(); i++){
        bool left = (i==0 ? true : nums[i] > nums[i-1]);
        bool right = (i==nums.size()-1 ? true : nums[i] > nums[i+1]);
        if(left && right) res++;
    }

    cout << res << endl;
    return 0;
}