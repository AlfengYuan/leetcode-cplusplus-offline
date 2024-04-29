#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]){
    int n;
    cin >> n;
    int start, m;
    vector<bool> heap(100, false);
    while(cin >> start >> m){
        for(int i = start; i<start+m; i++){
            if(heap[i]) {
                cout << -1 << endl;
                return 0;
            }
            heap[i] = true;
        }
    }

    for(int i = 0; i<100; i++){
        int j = i;
        while(j<100 && heap[j]) j++;
        int k = j;
        while(k<100 && !heap[k]) k++;
        if(k - j >= n){
            cout << j << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}