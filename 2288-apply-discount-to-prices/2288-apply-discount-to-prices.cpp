class Solution {
public:
    string h(string word, int dis) {
        if(word[0]!='$' or word.size()==1)
            return word;
        int cnt_dot=0;
        for(int i=1 ; i<word.size() ; ++i) {
            if(!isdigit(word[i]) and word[i]!='.')
                return word;
            if(word[i]=='.')
                cnt_dot++;
        }
        if(cnt_dot>1) return word;
        double rem = (100-dis)/100.0;
        stringstream s;
        s<<fixed<<setprecision(2)<<(rem*stod(word.substr(1)));
        return "$"+s.str();
    }
    string discountPrices(string sentence, int discount) {
        stringstream s(sentence);
        string ans,t;
        while(s>>t) {
            ans += h(t, discount) + " ";
        }
        ans.pop_back();
        return ans;
    }
};