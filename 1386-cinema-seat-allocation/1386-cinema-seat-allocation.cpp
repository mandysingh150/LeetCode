class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& a) {
        int pre=1, cnt=0;
        sort(begin(a), end(a));
        for(int i=0 ; i<a.size() ; ) {
            cnt += 2*(a[i][0]-pre);
            int x = a[i][0], l1=0, l2=0, r1=0, r2=0;
            while(i<a.size() and a[i][0]==x) {
                if(a[i][1]>1 and a[i][1]<10) {
                    if(a[i][1] <= 3) l1=1;
                    else if(a[i][1] <= 5) l2=1;
                    else if(a[i][1] <= 7) r1=1;
                    else r2=1;
                }
                i++;
            }
            if(!l1 and !l2 and !r1 and !r2) 
                cnt += 2;
            else {
                if(!l1 and !l2) cnt++;
                else if(!l2 and !r1) cnt++;
                else if(!r1 and !r2) cnt++;
            }
            pre = a[i-1][0]+1;
        }
        return cnt + (n+1-pre)*2;
    }
};