/* https://ac.nowcoder.com/acm/contest/5657#question */
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    int a, t;
    while(1)
    {
        cin >> t;
        int sum = 0;
        if(t == 0) break;
        while(t-- && cin >> a) sum += a;
        cout << sum << endl;
    }
    return 0;
}