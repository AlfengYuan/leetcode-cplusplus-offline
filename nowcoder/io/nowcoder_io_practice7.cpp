/* https://ac.nowcoder.com/acm/contest/5657#question */
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    int sum=0, a;
    while(cin >> a)
    {
        sum += a;
        if(cin.get() == '\n')
        {
            cout << sum << endl;
            sum = 0;
        }
    }
    return 0;
}