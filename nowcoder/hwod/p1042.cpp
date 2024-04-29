#include <queue>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]){
    priority_queue<int> mypq;
    int n;
    cin >> n;
    int x;
    for(int i = 0; i<n; i++){
        cin >> x;
        mypq.push(x);
    }

    while(mypq.size() >= 3){
        int z = mypq.top(); mypq.pop();
        int y = mypq.top(); mypq.pop();
        int x = mypq.top(); mypq.pop();
        if(x==y==z) continue;
        else if(x==y && y != z){
            mypq.push(z-y);
        }else if(x!=y && y==z){
            mypq.push(y-x);
        }else if(x!=y && y!=z){
            mypq.push(abs(z-2*y+x));
        }
    }

    if(mypq.empty()) cout << 0 << endl;
    else cout << mypq.top() << endl;

    return 0;
}