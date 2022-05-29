class Solution {
public:
    int maxProduct(vector<string>& words) {
        int v[words.size()], mx=0;
        for(int i=0 ; i<words.size() ; ++i) {
            int cnt=0;
            for(int j=0 ; j<words[i].size() ; ++j)
                cnt |= (1<<(words[i][j]-'a'));
            v[i] = cnt;
            for(int j=0 ; j<i ; ++j)
                if((v[i]&v[j]) == 0)
                    mx = max(mx, int(words[i].size()*words[j].size()));
        }
        return mx;
    }
};