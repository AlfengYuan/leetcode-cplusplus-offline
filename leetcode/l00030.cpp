class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        vector<int> wordsInts;
        int wordLen = words[0].length();
        int wordsLen = words.size() * wordLen;
        if(s.length() < wordsLen) return result;
        int sum = 0;
        for (string& str : words) {
            sum += str2int(str);
        }
        vector<string> failedCollect;
        vector<string> successfulCollect;
        for (int i = 0; i <= s.length() - wordsLen; i++) {
            string curr = s.substr(i, wordsLen);
            if (str2int(curr) != sum)
            {
                continue;
            }
            else {
                vector<string>::iterator failedIter = find(failedCollect.begin(), failedCollect.end(), curr);
                vector<string>::iterator successIter = find(successfulCollect.begin(), successfulCollect.end(), curr);
                if(successIter != successfulCollect.end()) {
                    result.push_back(i);
                    continue;
                }
                else if(failedIter == failedCollect.end()){
                    vector<bool> used(words.size(), false);
                    bool flag = true;
                    for (int j = 0; j < curr.length(); j += wordLen) {
                        string currWordStr = curr.substr(j, wordLen);
                        if (!myfind(words, currWordStr, used)) {
                            flag = false;
                            break;
                        }
                    }
                    if (flag) {
                        successfulCollect.push_back(curr);
                        result.push_back(i);
                    }
                    else 
                    {
                        failedCollect.push_back(curr);
                    }
                }
                
            }
        }

        return result;

    }

    int str2int(string s){
        int result = 0;
        for (char& c : s) {
            result += (c - 'a');
        }
        return result;
    }

    bool myfind(vector<string> words, string curr, vector<bool>& used) {
        for (int i = 0; i < words.size(); i++) {
            if (curr == words[i] && used[i] == false) {
                used[i] = true;
                return true;
            }
        }

        return false;
    }
};