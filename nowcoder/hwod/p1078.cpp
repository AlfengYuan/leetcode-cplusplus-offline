#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

int n;
int w_watch, w_star, w_fork, w_issue, w_mr;
struct Leetcode{
    string name;
    string low_name;
    int watch;
    int star;
    int fork;
    int issue;
    int mr;
    int h;
};

int main(int argc, char *argv[]){
    cin >> n;
    cin >> w_watch >> w_star >> w_fork >> w_issue >> w_mr;
    string name = "", low_name = "";
    int watch, star, fork, issue, mr, h;
    vector<Leetcode> vec;
    for(int i = 0; i<n; i++){
        cin >> name >> watch >> star >> fork >> issue >> mr;
        h = w_watch * watch + w_star * star + w_fork * fork + w_issue * issue + w_mr * mr;
        low_name = "";
        for(int i = 0; i<name.length(); i++){
            if(name[i] >= 'A' && name[i] <= 'Z'){
                low_name += (name[i] + 32);
            }else{
                low_name += name[i];
            }
        }
        Leetcode l;
        l.name = name, l.watch = watch, l.star = star, l.fork = fork, l.issue = issue, l.mr = mr, l.h = h;
        l.low_name = low_name;
        
        vec.push_back(l);
    }

    sort(vec.begin(), vec.end(), [](Leetcode &a, Leetcode &b){
        if(a.h != b.h){
            return a.h > b.h;
        }else{
            return a.low_name < b.low_name;
        }
    });

    for(Leetcode &l: vec){
        cout << l.name << endl;
    }
    
    return 0;
}