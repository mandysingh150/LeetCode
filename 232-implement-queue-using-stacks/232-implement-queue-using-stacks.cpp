class MyQueue {
public:
    stack<int> a,b;
    MyQueue() {}
    
    void push(int x) {
        a.push(x);
    }
    
    int pop() {
        while(a.size() > 1) {
            b.push(a.top());
            a.pop();
        }
        int val = a.top();
        a.pop();
        while(!b.empty()) {
            a.push(b.top());
            b.pop();
        }
        return val;
    }
    
    int peek() {
        while(a.size() > 1) {
            b.push(a.top());
            a.pop();
        }
        int val = a.top();
        while(!b.empty()) {
            a.push(b.top());
            b.pop();
        }
        return val;
    }
    
    bool empty() {
        return a.size()==0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */