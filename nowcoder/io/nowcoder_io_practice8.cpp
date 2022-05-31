/* https://ac.nowcoder.com/acm/contest/5657#question */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[])
{
    vector<string> result;
    int num;
    string str;
    cin >> num;
    while(num-- && cin >> str) result.push_back(str);
    sort(result.begin(), result.end());
    for(string &s: result)
    {
        cout << s << " ";
    }
    cout << endl;
    return 0;
}