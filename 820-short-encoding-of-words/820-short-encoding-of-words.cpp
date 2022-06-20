class Solution {
public:
    int minimumLengthEncoding(vector<string>& a) {
        int n=a.size();
        vector<int> v(n, 1);
        sort(a.begin(), a.end(), [](string &c, string &d) {
            return c.size() < d.size();
        });
        for(int i=0 ; i<n ; ++i) {
            for(int j=i+1 ; j<n ; ++j) {
                int diff = a[j].size()-a[i].size();
                if(a[j][diff] == a[i][0] and a[j].substr(a[j].size()-a[i].size()).compare(a[i]) == 0) {
                    v[i] = 0;
                    break;
                }
            }
        }
        int cnt=0;
        for(int i=0 ; i<v.size() ; ++i) {
            if(v[i]) {
                cnt += a[i].size() + 1;
            }
        }
        return cnt;
    }
};