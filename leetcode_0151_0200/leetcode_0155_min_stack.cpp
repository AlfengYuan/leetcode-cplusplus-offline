#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class MinStack {
    vector<int> mystack;
public:
    MinStack() {
        this->mystack.clear();
    }
    
    void push(int val) {
        this->mystack.push_back(val);
    }
    
    void pop() {
        this->mystack.pop_back();
    }
    
    int top() {
        return this->mystack[mystack.size()-1];

    }
    
    int getMin() {
        return *min_element(this->mystack.begin(), this->mystack.end());
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main(int argc, char *argv[])
{
    MinStack* obj = new MinStack();
    obj->push(-2);
    obj->push(0);
    obj->push(-3);
    cout << obj->getMin() << " ";
    obj->pop();
    cout << obj->top() << " ";
    cout << obj->getMin() << endl;
    return 0;
}