class Solution {
public:
    bool checkPossibility(vector<int>& a) {
        int min_steps=0;
        for(int i=1 ; i<a.size() ; ++i) {
            if(a[i-1] > a[i]) {
                if(i-2>=0 and a[i-2]>a[i]) {
                    a[i]=a[i-1];
                }
                else {
                    a[i-1]=a[i];
                }
                min_steps++;
            }
        }
        return min_steps<=1;
    }
};