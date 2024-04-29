#include <cctype>
#include <vector>
#include <string>
#include <iostream>
#include <queue>
using namespace std;

int compute(string &s, int left, int right){
    char op = '$';
    int num = 0;
    deque<int> st;
    for(int i = left; i<=right; i++){
        if(isdigit(s[i])){
            num = num * 10 + s[i] - '0';
        }

        if(!isdigit(s[i]) || i == right){
            switch (op) {
                case '$':
                    st.push_back(num);
                    break;
                case '#':
                    int x = st.back();
                    st.pop_back();
                    st.push_back(4*x + 3*num + 2);
                    break;
            }
            op = s[i];
            num = 0;
        }
    }
    while(st.size() > 1){
        int x = st.front(); st.pop_front();
        int y = st.front(); st.pop_front();
        st.push_front(2 * x + y + 3);
    }

    return st.front();
}
int main(int argc, char *argv[]){
    string input;
    cin >> input;
    int res = compute(input, 0, input.length()-1);
    cout << res << endl;

    return 0;
}