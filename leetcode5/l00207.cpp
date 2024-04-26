#include <vector>
#include <iostream>

using namespace std;

class Solution {
    vector<vector<int>> edges;
    vector<int> degree;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        edges = vector<vector<int>>(numCourses, vector<int>());
        degree = vector<int>(numCourses, 0);
        for(auto &pre : prerequisites){
            edges[pre[1]].push_back(pre[0]);
            degree[pre[0]]++;
        }

        vector<int> res;
        vector<int> vec;
        deque<int> mydeque;
        for(int i = 0; i<degree.size(); i++){
            if(degree[i] == 0){
                vec.push_back(i);
                mydeque.push_back(i);
            }
        }

        while(!mydeque.empty()){
            int curr = mydeque.front();
            mydeque.pop_front();
            sort(vec.begin(), vec.end());
            for(int i = 0; i<vec.size(); i++){
                res.push_back(vec[i]);
            }
            vec.clear();

            for(int &i: edges[curr]){
                degree[i]--;
                if(degree[i] == 0){
                    vec.push_back(i);
                    mydeque.push_back(i);
                }
            } 
        }

        return res.size() == numCourses;

    }
};