class MedianFinder {
public:
    priority_queue<int> mx;
    priority_queue<int, vector<int>, greater<int>> mn;
    MedianFinder() {}
    
    void addNum(int num) {
        if(mx.empty() or num <= mx.top()) {
            mx.push(num);
        }
        else {
            mn.push(num);
        }
        while(mx.size() < mn.size()) {
            mx.push(mn.top());
            mn.pop();
        }        
        while(mx.size() > mn.size()+1) {
            mn.push(mx.top());
            mx.pop();
        }
    }
    
    double findMedian() {
        return (mx.size() == mn.size() ? (1.0*mx.top()+mn.top())/2 : mx.top());
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */