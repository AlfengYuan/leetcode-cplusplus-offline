/* https://ac.nowcoder.com/acm/contest/5657#question */
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    int a, t;
    while(cin >> t)
    {
        int sum = 0;
        while(t-- && cin >> a) sum += a;
        cout << sum << endl;
    }
    return 0;
}