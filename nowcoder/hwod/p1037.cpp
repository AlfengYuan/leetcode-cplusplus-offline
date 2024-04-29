#include <cctype>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]){
    int k;
    cin >> k;
    string input;
    cin >> input;
    string res = "";
    int i = 0;

    string tmp = "";
    for(; i<input.length(); i++){
        res += input[i];
        if(input[i] == '-') break;
    }

    int low = 0, uper = 0;
    for(; i<input.length(); i++){
        if(input[i] == '-') continue;
        if(isalpha(input[i])){
            if(input[i] >= 'A' && input[i] <= 'Z'){
                uper++;
            }else{
                low++;
            }
        }
        tmp += input[i];

        if(tmp.length() == k || i==input.length()-1){
            if(uper==low){    
            }else if(uper > low){
                for(int j = 0; j<tmp.length(); j++){
                    if(isalpha(tmp[j]) && tmp[j] >= 'a' && tmp[j] <= 'z'){
                        tmp[j] = toupper(tmp[j]);
                    }
                }
            }else{
                for(int j = 0; j<tmp.length(); j++){
                    if(isalpha(tmp[j]) && tmp[j] >= 'A' && tmp[j] <= 'Z'){
                        tmp[j] = tolower(tmp[j]);
                    }
                }
            }
            tmp.push_back('-');
            res += tmp;
            tmp = "";
            low = 0;
            uper = 0;
        }
    }

    res.pop_back();

    cout << res << endl;

    return 0;
}