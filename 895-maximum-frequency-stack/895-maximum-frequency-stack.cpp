class FreqStack {
public: 
    unordered_map<int,int> mp;
    // {frequency, {timestamp, element}}
    priority_queue<pair<int,pair<int,int>>> pq;
    int time;
    FreqStack() {
        time=0;
    }
    
    void push(int val) {
        pq.push({++mp[val], {++time, val}});
    }
    
    int pop() {
        auto top = pq.top();
        pq.pop();
        mp[top.second.second]--;
        return top.second.second;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */