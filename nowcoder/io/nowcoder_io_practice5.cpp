#include <iostream>
using namespace std;

/* https://ac.nowcoder.com/acm/contest/5657#question */
int main(int argc, char *argv[])
{
    int a, t, b;
    cin >> b;
    while(b--)
    {
        cin >> t;
        int sum = 0;
        if(t == 0) continue;
        while(t-- && cin >> a) sum += a;
        cout << sum << endl;
    }
    return 0;
}