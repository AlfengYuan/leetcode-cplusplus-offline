class MinStack {
public:
    MinStack() {

    }
    
    void push(int val) {
        this->vec.push_back(val);
    }
    
    void pop() {
        this->vec.pop_back();
    }
    
    int top() {
        return this->vec[this->vec.size()-1];
    }
    
    int getMin() {
        return *min_element(this->vec.begin(), this->vec.end());
    }
private:
    vector<int> vec;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */