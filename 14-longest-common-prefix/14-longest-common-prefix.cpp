class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s="";
        for(int i=0 ; i<strs[0].size() ; ++i) {
            char ch=strs[0][i];
            bool same=1;
            for(auto str: strs) {
                if(i<str.size() and str[i]==ch)
                    continue;
                same=0;
                break;
            }
            if(same)
                s.push_back(ch);
            else
                break;
        }
        return s;
    }
};