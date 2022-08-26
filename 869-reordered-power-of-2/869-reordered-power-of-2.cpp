class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string t=to_string(n);
        int a[10]={0};
        for(auto i: t) a[i-'0']++;
        for(int i=0 ; i<=30 ; ++i) {
            int val = (1<<i);
            string s=to_string(val);
            int b[10]={0};
            for(auto d: s) b[d-'0']++;
            bool found=1;
            for(int j=0 ; j<10 ; ++j) {
                if(a[j] != b[j]) {
                    found=0;
                    break;
                }
            }
            if(found) return 1;
        }
        // sort(begin(t), end(t));
        // while(t[0]=='0') next_permutation(begin(t), end(t));
        // // do {
        // //     int a = stoi(t);
        // //     if((a&(a-1)) == 0) return 1;
        // // } while(next_permutation(begin(t), end(t)));
        return 0;
    }
};