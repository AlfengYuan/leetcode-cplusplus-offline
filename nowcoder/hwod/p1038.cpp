#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(int argc, char *argv[]){
    string input;
    cin >> input;
    int oNum;
    for(int i = 0; i<input.length(); i++){
        if(input[i]=='o') oNum++;
    }

    if(oNum % 2 == 0) cout << input.length() << endl;
    else cout << input.length()-1 << endl;

    return 0;
}