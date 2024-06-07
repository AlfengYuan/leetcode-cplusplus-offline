#include <vector>
#include <iostream>
#include <string>

using namespace std;


vector<bool> countPrimes(int n) {
    vector<bool> is_prime(n, true);
    for(int i = 2; i*i < n; i++){
        if(is_prime[i]){
            for(int j = i * i; j<n; j+=i){
                is_prime[j] = false;
            }
        }
    }

    return is_prime;
}

int main(int argc, char *argv[]){
    int n;
    cin >> n;

    vector<bool> is_prime = countPrimes(n);

    for(int i = 2; i<n; i++){
        if(is_prime[i] && n % i == 0 && is_prime[n/i]){
            cout << i << " " << n/i << endl;
            return 0;
        }
    }

    cout << -1 << " " << -1 << endl;

    return 0;
}