#include <string>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

int main(int argc, char *argv[]){
    vector<vector<string>> vec;
    int n;
    string input;
    getline(cin, input);
    n = atol(input.c_str());
    vector<bool> good;
    for(int i = 0; i<n; i++){
        int absentNum = 0;
        int lateNum = 0;
        int leaveearlyNum = 0;
        int presentNum = 0;
        getline(cin, input);
        stringstream ss(input);
        string tmp;
        vector<string> curr;
        bool flag = true;
        while(getline(ss, tmp, ' ')){
            if(tmp == "absent") absentNum++;
            else if(tmp=="late") {
                lateNum++;
                if((!curr.empty() && curr.back() == "late") || (!curr.empty() && curr.back() == "leaveearly")){
                    cout << "false" << endl;
                    flag = false;
                    break;
                }
            }
            else if(tmp=="leaveearly") {
                leaveearlyNum++;
                if((!curr.empty() && curr.back() == "late") || (!curr.empty() && curr.back() == "leaveearly")){
                    cout << "false" << endl;
                    flag = false;
                    break;
                }
            }else{
                presentNum++;
            }

            if(absentNum > 1) {
                cout << "false" << endl;
                flag = false;
                break;
            }

            curr.push_back(tmp);

            if(curr.size()==7){
                if(presentNum < 4){
                    flag = false;
                    cout << "false" << endl;
                    break;
                }else{
                    if(curr[0]=="present"){
                        presentNum--;
                    }
                    curr.erase(curr.begin());
                }
            }

            
        }

        if(flag) cout << "true" << endl;

    }

    return 0;
}