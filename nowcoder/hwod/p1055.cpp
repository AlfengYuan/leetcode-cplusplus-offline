#include <iostream>

using namespace std;
int main(int argc, char *argv[]){
    int x;
    cin >> x;
    int m = x / 3;
    int p = x % 3;
    if(p==2){
        cout << 2 << " ";
        for(int i = 0; i<m; i++){
            cout << 3 << " ";
        }
        cout << endl;
    }else if(p==1){
        for(int i = 0; i<m-1; i++){
            cout << 3 << " ";
        }
        cout << 4 << endl;
    }else if(p==0){
        for(int i = 0; i<m; i++){
            cout << 3 << " ";
        }
        cout << endl;
    }

    return 0;

}