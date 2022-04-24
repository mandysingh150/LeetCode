class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int,int> count_gaps_at_position;
        int mx = 0;
        for(auto i: wall) {
            int sum = 0;
            for(int j=0 ; j<i.size()-1 ; ++j) {
                sum += i[j];
                mx = max(mx, ++count_gaps_at_position[sum]);
            }
        }
        return wall.size()-mx;
    }
};