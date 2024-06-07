#include <vector>
#include <iostream>
#include <string>
#include <numeric>
#include <iomanip>
#include <algorithm>
#include <climits>
using namespace std;


int main(int argc, char *argv[]){
    int cap, num;
    cin >> cap;
    cin >> num;

    vector<int> tasks(num, 0);
    for(int i = 0; i<num; i++){
        cin >> tasks[i];
    }

    int last = 0;
    int t = 0;
    for(int i = 0; i<num; i++){
        if(tasks[i] + last > cap){
            last = (tasks[i] + last - cap);
        }else{
            last = 0;
        }
        t++;
    }

    while(last > 0){
        last -= cap;
        t++;
    }

    cout << t << endl;

    return 0;
}