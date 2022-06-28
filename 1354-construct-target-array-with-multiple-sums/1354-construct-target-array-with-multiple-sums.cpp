class Solution {
public:
    bool isPossible(vector<int>& a) {
        if(a.size() == 1)
            return a.front()==1;
        priority_queue<long long> pq;
        long long sum=0;
        for(auto i: a) {
            pq.push(i);
            sum += i;
        }
        while(pq.top() != 1) {
            auto top = pq.top();
            pq.pop();
            
            if(sum-top == 1)
                return 1;
            
            long long val = top%(sum-top);
            sum += val - top;
            
            if(val==0 or val==top)
                return 0;
            pq.push(val);
        }
        return 1;
    }
};