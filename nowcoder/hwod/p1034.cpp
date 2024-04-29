#include <vector>
#include <iostream>

using namespace std;
vector<int> vec;

int getPrice(int x){
    int y = (x+1) % vec.size();
    while(y != x && vec[y] >= vec[x]) y = ((y +1) % vec.size());
    if(y == x) return vec[x];
    else return vec[x]+vec[y];
}
int main(int argc, char *argv[]){
    int x;
    
    while(cin >> x){
        vec.push_back(x);
        if(cin.get() == '\n') break;
    }

    vector<int> res;

    for(int i = 0; i<vec.size(); i++){
        res.push_back(getPrice(i));
    }

    for(int i = 0; i<res.size(); i++){
        cout << res[i];
        if(i != res.size()-1) cout << " ";
    }

    cout << endl;
    return 0;
}