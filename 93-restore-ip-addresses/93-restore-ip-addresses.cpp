class Solution {
public:
    vector<string> a;
    void h(string &ip, int i, string &t, int dot) {
        if(i >= ip.size()) {
            if(dot==0)
                a.push_back(t);
            return;
        }
        if(dot==0)
            return;
        if(ip[i] == '0') {
            t += string(1, ip[i]) + ".";
            h(ip, i+1, t, dot-1);
            t.pop_back();
            t.pop_back();
        }
        else {
            int val=0, cnt=0, index=0;
            while(i+cnt<ip.size()) {
                val = (val*10) + (ip[i+cnt]-'0');
                if(val>255)
                    break;
                string temp(1, ip[i+cnt]);
                t += string(1, ip[i+cnt]) + ".";
                h(ip, i+cnt+1, t, dot-1);
                t.pop_back();
                ++cnt;
            }
            while(cnt--)
                t.pop_back();
        }
    }
    vector<string> restoreIpAddresses(string s) {
        a.clear();
        string t="";
        h(s, 0, t, 4);
        for(int i=0 ; i<a.size() ; ++i)
            a[i].pop_back();
        sort(begin(a), end(a));
        return a;
    }
};