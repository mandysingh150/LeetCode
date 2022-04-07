class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto i: stones)
            pq.push(i);
        while(pq.size() > 1) {
            auto top1 = pq.top(); pq.pop();
            auto top2 = pq.top(); pq.pop();
            if(top1 != top2 or pq.empty())
                pq.push(top1-top2);
        }
        return pq.top();
    }
};