class Solution {
public:
    int scheduleCourse(vector<vector<int>>& a) {
        priority_queue<int> pq;
        int time=0;
        sort(begin(a), end(a), [](auto &c, auto &d) {
            return c[1] < d[1];
        });
        for(auto i: a) {
            // if we can take finish the course on or before the last day, then we are taking the course
            if(time + i[0] <= i[1]) {
                time += i[0];
                pq.push(i[0]);
            }
            // here, we are trying to minimize the total time of all the taken courses
            // this is done by replacing a previously taken "longer duration" course with the current course
            else if(!pq.empty() and pq.top() > i[0]) {
                time += i[0] - pq.top();
                pq.pop();
                pq.push(i[0]);
            }
        }
        return pq.size();
    }
};