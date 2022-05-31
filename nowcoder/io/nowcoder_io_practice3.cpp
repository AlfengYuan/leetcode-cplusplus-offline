/* https://ac.nowcoder.com/acm/contest/5657#question */
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    int a, b;
    while(cin >> a >> b)
    {
        if(a==0 && b==0) break;
        cout << a + b << endl;
    }

    return 0;
}