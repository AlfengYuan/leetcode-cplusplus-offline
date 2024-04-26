#include <iostream>
#include <queue>
#include <string>

using namespace std;

class MyStack {
    queue<int> qA;
    queue<int> qB;
public:
    MyStack() {

    }
    
    void push(int x) {
        if(qA.empty() && qB.empty()){
            qA.push(x);
        }else if(!qA.empty()){
            qA.push(x);
        }else if(!qB.empty()){
            qB.push(x);
        }else{
            throw std::runtime_error("bad case!");
        }
    }
    
    int pop() {
        int res = -1;
        if(!qA.empty()){
            while(qA.size() > 1){
                qB.push(qA.front()); qA.pop();
            }
            res = qA.front();
            qA.pop();
            return res;
        }else if(!qB.empty()){
            while(qB.size() > 1){
                qA.push(qB.front()); qB.pop();
            }
            res = qB.front();
            qB.pop();
            return res;
        }else{
            throw std::runtime_error("bad case!");
        }

        return res;
    }
    
    int top() {
        int res = -1;
        if(!qA.empty()){
            while(qA.size() > 1){
                qB.push(qA.front()); qA.pop();
            }
            res = qA.front();
            qB.push(res); qA.pop();
            return res;
        }else if(!qB.empty()){
            while(qB.size() > 1){
                qA.push(qB.front()); qB.pop();
            }
            res = qB.front();
            qA.push(res); qB.pop();
            return res;
        }else{
            throw std::runtime_error("bad case!");
        }

        return res;
    }
    
    bool empty() {
        return qA.empty() && qB.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */