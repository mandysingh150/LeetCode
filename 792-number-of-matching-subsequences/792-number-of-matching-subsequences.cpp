class Solution {
public:
    bool isFound(string &s, string &sub, int offset, int offSub) {
        if(offSub == sub.size())
            return 1;
        if(offset >= s.size())
            return 0;
        
        offset = s.find(sub[offSub], offset);
        if(offset == string::npos)
            return 0;
        
        return isFound(s, sub, offset+1, offSub+1);
    }
    
    int numMatchingSubseq(string &s, vector<string>& words) {
        int cnt = 0;
        for(auto i: words)
            if(isFound(s, i, 0, 0))
                cnt++;
        return cnt;
    }
};