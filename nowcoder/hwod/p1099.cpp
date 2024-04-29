#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(int argc, char *argv[]){
    string input;
    cin >> input;
    int n = 0;
    string str = "";
    vector<bool> flag(10, false);
    for(int i = 0; i<input.length(); i++){
        if(input[i] == ',') continue;
        else if(!isdigit(input[i]) || input[i] == '0'){
            cout << -1 << endl;
            return 0;
        }
        else if(input[i] == '5' || input[i]=='2'){
            if(flag[5] || flag[2]){
                cout << -1 << endl;
                return 0;
            }
            flag[5] = true;
            flag[2] = true;
            str += "2";
            str += "5";
        }else if(input[i] == '9' || input[i] == '6'){
            if(flag[6] || flag[9]){
                cout << -1 << endl;
                return 0;
            }
            flag[6] = true;
            flag[9] = true;
            str += "6";
            str += "9";
        }else{
            if(flag[input[i] - '0']){
                cout << -1 << endl;
                return 0;
            }
            str += input[i];
            flag[input[i] - '0'] = true;
        }

        n = max(n, input[i] - '0');
    }

    sort(str.begin(), str.end());
    int len = str.length();

    if(n <= len){
        cout << str[n-1] << endl;
    }else if(n <= 2 * len - 1){
        if(len == 4){
            cout << str[0] << str[n-len] << endl;
        }else{
            string res = "";
            res += str[0];
            int j = 1;
            for(int i = 0; i<n-len; i++){
                res = "";
                res += str[0];
                while(j < len){
                    res += str[j];
                    if(res == "25" || res == "52" || res == "69" || res == "96"){
                        res.pop_back();
                        j++;
                    }
                    else{
                        j++;
                        break;
                    }
                }
            }
            cout << res << endl;
            
        } 
    }else if(len==4 && n==8){
        cout << str[1];
        cout << str[0] << endl;
    }else if(len==4 && n==9){
        cout << str[1];
        cout << str[2] << endl;
    }

    return 0;
}