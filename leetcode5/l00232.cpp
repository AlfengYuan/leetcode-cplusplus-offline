class MyQueue {
public:
    MyQueue() {

    }
    
    void push(int x) {
        this->A.push(x);
    }
    
    int pop() {
        if(!this->B.empty()) {
            int x = B.top();
            B.pop();
            return x;
        }
        else{
            while(!A.empty()){
                B.push(A.top());
                A.pop();
            }
            int x = B.top();
            B.pop();
            return x;
        }
    }
    
    int peek() {
        if(!this->B.empty())  return B.top();
        else{
            while(!A.empty()){
                B.push(A.top());
                A.pop();
            }
            return B.top();
        }
    }
    
    bool empty() {
        if(A.empty() && B.empty()) return true;
        return false;
    }
private:
    stack<int> A;
    stack<int> B;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */