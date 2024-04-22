class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1 = split(version1);
        vector<int> v2 = split(version2);
        while(v1.size() < v2.size()) v1.push_back(0);
        while(v2.size() < v1.size()) v2.push_back(0);
        // for(int &v: v1){
        //     cout << v << ",";
        // }
        // cout << endl;

        // for(int &v: v2){
        //     cout << v << ",";
        // }
        // cout << endl;

        for(int i = 0; i<v1.size(); i++){
            if(v1[i] > v2[i]){
                return 1;
            }else if(v1[i] < v2[i]){
                return -1;
            }
        }
        return 0;
    }

    vector<int> split(string version1){
        vector<int> v1;
        for(int i = 0; i<version1.length(); i++){
            int j = i;
            while(j < version1.length() && version1[j] != '.') j++;
            string curr = version1.substr(i, j-i);
            v1.push_back(atol(curr.c_str()));
            i = j;
        }
        //while(v1.size() < 4) v1.push_back(0);
        return v1;
    }
};