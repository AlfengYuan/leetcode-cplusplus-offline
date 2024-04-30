#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <unordered_map>
#include <numeric>
#include <cmath>
using namespace std;


int main(int argc, char *argv[]){
    int n1, n2, x, k;
    cin >> n1;
    vector<int> array1(n1, 0);
    for(int i = 0; i<n1; i++){
        cin >> x;
        array1[i] = x;
    }
    cin >> n2;
    vector<int> array2(n2, 0);
    for(int i = 0; i<n2; i++){
        cin >> x;
        array2[i] = x;
    }
    cin >> k;

    //sort(array1.begin(), array1.end());
    //sort(array2.begin(), array2.end());

    vector<int> sum;
    for(int i = 0; i<n1; i++){
        for(int j = 0; j<n2; j++){
            sum.push_back(array1[i] + array2[j]);
        }
    }

    sort(sum.begin(), sum.end());

    k = min(k, static_cast<int>(sum.size()));

    cout << accumulate(sum.begin(), sum.begin()+k, 0) << endl;


    
    // for(int &i: array1) cout << i << ",";
    // cout << endl;

    // for(int &i: array2) cout << i << ",";
    // cout << endl;

    // cout << k << endl;


    return 0;
}

// {2, 5, 30, 34, 35, 36, 37, 40, 42, 44, 47, 50, 54, 66, 76, 84, 90, 104, 105, 107, 117, 120, 126, 137, 138, 150, 157, 168, 175, 183, 191, 191, 193, 
//   198, 230, 240, 249, 261, 265, 267, 273, 284, 288, 291, 295, 310, 324, 328, 331, 333, 357, 358, 365, 367, 374, 410, 416, 417, 426, 435, 437, 446, 458, 476, 481, 485, 495, 509, 510, 511, 512, 525, 
//   533, 535, 558, 576, 591, 620, 624, 634, 634, 635, 640, 647, 656, 668, 669, 680, 695, 696, 698, 703, 704, 704, 709, 741, 747, 747, 750, 750, 753, 754, 757, 766, 770, 775, 779, 786, 791, 799, 811, 
//   811, 817, 821, 845, 855, 859, 860, 862, 875, 875, 877, 878, 884, 890, 891, 905, 916, 938, 939, 943, 960, 972, 981, 985, 992, 998}

// {23, 57, 88, 140, 279, 335, 350, 570, 656, 818, 898, 903, 903}