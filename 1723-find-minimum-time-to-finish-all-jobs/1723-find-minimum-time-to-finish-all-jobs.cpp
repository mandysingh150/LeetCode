class Solution {
public:
    int ans, workers[12];
    void dfs(vector<int> &jobs, int in, int k, int max_val) {
        if(in == jobs.size()) {
            ans = min(ans, max_val);
            return;
        }
        unordered_set<int> s;
        for(int i=0 ; i<k ; ++i) {
            // branch cutting step
            if(s.count(workers[i]))
                continue;
            // another branch cutting step
            if(workers[i] + jobs[in] >= ans)
                continue;
            
            s.insert(workers[i]);
            workers[i] += jobs[in];
            dfs(jobs, in+1, k, max(workers[i], max_val));
            workers[i] -= jobs[in];
        }
    }
    int minimumTimeRequired(vector<int>& jobs, int k) {
        if(k == jobs.size())
            return *max_element(begin(jobs), end(jobs));
        
        sort(begin(jobs), end(jobs), greater<int>());
        memset(workers, 0, sizeof(workers));
        ans = 0;
        // setting max value of 'ans'
        for(auto i: jobs) {
            ans += i;
        }
        dfs(jobs, 0, k, 0);
        return ans;
    }
};