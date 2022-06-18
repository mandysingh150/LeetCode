class Solution {
public:
    string add(string &s, string &t, int cnt) {
        // int c = 0, i=s.size()-1, j=t.size()-1;
        // string ans = "";
        // while(cnt-- && i>=0)
        //     ans = s[i--] + ans;
        // for( ; i>=0 && j>=0 ; --i, --j) {
        //     int sum = (s[i]-'0') + (t[j]-'0') + c;
        //     ans = (char)((sum%10)+'0') + ans;
        //     c = sum/10;
        // }
        // while(i>=0) {
        //     int sum = (s[i--]-'0') + c;
        //     ans = (char)((sum%10)+'0') + ans;
        //     c = sum/10;
        // }
        // while(j>=0) {
        //     int sum = (t[j--]-'0') + c;
        //     ans = (char)((sum%10)+'0') + ans;
        //     c = sum/10;
        // }        
        // if(c > 0)
        //     ans = (char)(c+'0') + ans;
        // return ans;
        
        // Short code
        string ans = "";
        int c = 0, i = s.size() - 1, j = t.size() - 1;
        while(cnt-- && i>=0)
            ans = s[i--] + ans;
        while(i >= 0 || j >= 0 || c == 1) {
            c += (i>=0 ? s[i--]-'0' : 0);
            c += (j>=0 ? t[j--]-'0' : 0);
            ans = char((c%10)+'0') + ans;
            c /= 10;
        }
        return ans;
    }
    string multiply(string s1, string s2) {
        // My logic
        // string ans = "";
        // for(int i=s1.size()-1 ; i>=0 ; --i) {
        //     int val = s1[i]-'0', carry = 0;
        //     string t = "";
        //     for(int j=s2.size()-1 ; j>=0 ; --j) {
        //         int prod = ((s2[j]-'0')*val)+carry;
        //         t = (char)((prod%10)+'0') + t;
        //         carry = prod/10;
        //     }
        //     if(carry > 0)
        //         t = (char)(carry+'0') + t;
        //     ans = add(ans, t, s1.size()-i-1);
        // }
        // int i=0;
        // for( ; i<ans.size()-1 && ans[i]=='0' ; ++i);
        // return ans.substr(i);
        
        // Shortened code
        string s(s1.size()+s2.size(), '0');
        for(int i=s1.size()-1 ; i>=0 ; --i) {
            int carry = 0;
            for(int j=s2.size()-1 ; j>=0 ; --j) {
                int prod = (s[i+j+1]-'0') + (s1[i]-'0') * (s2[j]-'0') + carry;
                s[i+j+1] = (prod%10) + '0';
                carry = prod/10;
            }
            s[i] += carry;
        }
        size_t startpos = s.find_first_not_of("0");
        if (string::npos != startpos)
            return s.substr(startpos);
        return "0";
    }
};