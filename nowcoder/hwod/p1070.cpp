#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

typedef struct Student{
    int index;
    int h;
    int w;

    Student(int x, int y, int z){index = x; h = y; w = z;}
}Stu;

int main(int argc, char *argv[]){
    cin >>n;
    int x;
    vector<Stu> vec(n, Student(0, 0, 0));

    for(int i = 0; i<n; i++){
        cin >> x;
        vec[i].index = i+1;
        vec[i].h = x; 
    }

    for(int i = 0; i<n; i++){
        cin >> x;
        vec[i].w = x;
    }

    sort(vec.begin(), vec.end(), [](Stu &a, Stu &b){
        if(a.h != b.h){
            return a.h < b.h;
        }else{
            if(a.w != b.w){
                return a.w < b.w;
            }else{
                return a.index < b.index;
            }
        }

    });

    for(int i = 0; i<vec.size(); i++){
        cout << vec[i].index;
        if(i != vec.size()-1) cout << " ";
    }

    cout << endl;

    return 0;
}