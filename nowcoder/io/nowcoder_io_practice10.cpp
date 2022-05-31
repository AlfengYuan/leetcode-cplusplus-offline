/* https://ac.nowcoder.com/acm/contest/5657#question */
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<sstream>

using namespace std;
int main(){
    
    string s;
    char ch;
    while(getline(cin,s)){ 
        stringstream ss(s);
        string tmp;
        vector<string> ans;
        while(getline(ss,tmp,',')){
            ans.push_back(tmp);
        }
        sort(ans.begin(),ans.end());
        
        for(int i=0;i<ans.size()-1;i++){
            cout<<ans[i]<<",";
        }
        cout<<ans[ans.size()-1]<<endl;
    }
    return 0;
}