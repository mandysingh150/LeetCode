class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        int a[26]={0};
        for(auto i: tasks) a[i-'A']++;
        for(int i=0 ; i<26 ; ++i) if(a[i] > 0) pq.push(a[i]);

        int all_time=0;
        while(!pq.empty()) {
            vector<int> v;
            int time=0;
            for(int i=0 ; i<n+1 ; ++i) {
                if(!pq.empty()) {
                    v.push_back(pq.top());
                    pq.pop();
                    time++;
                }
            }
            for(auto i: v) if(--i > 0) pq.push(i);
            all_time += !pq.empty() ? n+1 : time;
        }
        return all_time;
    }
};