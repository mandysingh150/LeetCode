class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> v;
        for(auto i: words) {
            int cnt=0;
            for(auto j: i)
                cnt |= (1<<(j-'a'));
            v.push_back(cnt);
        }
        int mx = 0;
        for(int i=0 ; i<v.size() ; ++i)
            for(int j=0 ; j<v.size() ; ++j)
                if((v[i]&v[j]) == 0)
                    mx = max(mx, int(words[i].size()*words[j].size()));
        return mx;
    }
};