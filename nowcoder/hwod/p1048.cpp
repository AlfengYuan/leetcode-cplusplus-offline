#include <numeric>
#include <ratio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[]){
    int l1, l2, x;
    cin >> l1 >> l2;
    vector<int> A;
    vector<int> B;
    for(int i = 0; i<l1; i++){
        cin >> x;
        A.push_back(x);
    }

    for(int i = 0; i<l2; i++){
        cin >> x;
        B.push_back(x);
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int sumA = accumulate(A.begin(), A.end(), 0);
    int sumB = accumulate(B.begin(), B.end(), 0);
    for(int i = 0; i<A.size(); i++){
        for(int j = 0; j<B.size(); j++){
            int swapA = sumA - A[i] + B[j];
            int swapB = sumB - B[j] + A[i];
            if(swapA==swapB){
                cout << A[i] << " " << B[j] << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}