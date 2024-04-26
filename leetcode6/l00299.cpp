class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> mymap;
        vector<bool> used(secret.length(), false);
        int bulls = 0, cows = 0;
        for(int i = 0; i<secret.length(); i++){
            if(mymap.count(secret[i]) > 0){
                mymap[secret[i]]++;
            }else{
                mymap[secret[i]] = 1;
            }
        }

        for(int i = 0; i<secret.length(); i++){
            if(secret[i] == guess[i]){
                bulls++;
                mymap[secret[i]]--;
                used[i] = true;
            }
        }

        for(int i = 0; i<guess.length(); i++){
            if(mymap.count(guess[i]) > 0 && mymap[guess[i]] > 0 && !used[i]){
                cows++;
                mymap[guess[i]]--;
            }
        }

        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};