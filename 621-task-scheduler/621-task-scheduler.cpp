class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int time=0;
        int cnt[26]={0};
        for(auto i: tasks) {
            cnt[i-'A']++;
        }
        priority_queue<int> pq;
        for(int i=0 ; i<26 ; ++i) {
            if(cnt[i] > 0) {
                pq.push(cnt[i]);
            }
        }
        while(1) {
            for(int i=0 ; i<26 ; ++i) {
                cnt[i]=0;
            }
            int k=n+1, sz=0;
            while(!pq.empty() and k) {
                auto top=pq.top();
                pq.pop();
                if(top-1 > 0) {
                    cnt[sz]=top-1;
                    sz++;
                }
                ++time;
                --k;
            }
            if(pq.empty() and sz==0)
                return time;
            time += k;
            for(int i=0 ; i<sz ; ++i) {
                if(cnt[i] > 0)
                    pq.push(cnt[i]);
            }
        }
        return 0;
    }
};