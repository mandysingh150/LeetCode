class MinStack {
public:
    stack<long long> s;
    long long mn;
    MinStack() {
        mn=INT_MAX;
    }
    
    void push(int val) {
        if(val < mn) {
            s.push(2ll*val-mn);
        }
        else {
            s.push(val);
        }
        mn = min(mn, 0ll+val);
    }
    
    void pop() {
        auto top = s.top();
        s.pop();
        if(top < mn) {
            mn = 2ll*mn-top;
        }
    }
    
    int top() {
        return s.top() < mn ? mn : s.top();
    }
    
    int getMin() {
        return mn;
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