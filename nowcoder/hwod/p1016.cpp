#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int n, m;
int courIndex;


typedef struct Student{
    string name;
    int scores[15];
}Stu;

int main(int argc, char *argv[]){
    Stu stus[105];
    string course[15];
    cin >> n >> m;

    string pat;
    courIndex = m;
    for(int i = 0; i<m; i++){
        cin >> course[i];
    }

    for(int i = 0; i<n; i++){
        cin >> stus[i].name;
        int sum = 0;
        for(int j = 0; j<m; j++){
            cin >> stus[i].scores[j];
            sum += stus[i].scores[j];
        }
        stus[i].scores[m] = sum;
    }

    cin >> pat;
    for(int i = 0; i<m; i++){
        if(pat == course[i]){
            courIndex = i;
            break;
        }
    }

    sort(stus, stus+n, [](Stu &a, Stu &b){
        if(a.scores[courIndex] != b.scores[courIndex]){
            return a.scores[courIndex] > b.scores[courIndex];
        }else{
            return a.name < b.name;
        }
    });

    for(int i = 0; i<n; i++){
        cout << stus[i].name;
        if(i != n-1) cout << " ";
    }

    cout << endl;
    return 0;
}