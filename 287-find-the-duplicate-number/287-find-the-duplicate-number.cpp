class Solution {
public:
    int findDuplicate(vector<int> a) {
        int n = a.size();
        
        // Approach 1 - Floyd's Tortiose and Hare algorithm
        int slow = 0, fast = 0;
        for(int i=0 ; i<n ; ++i) {
            slow = a[slow];
            fast = a[a[fast]];
            
            if(fast==slow) {
                slow = 0;
                while(slow!=fast) {
                    slow = a[slow];
                    fast = a[fast];
                }
                return slow;    // or return fast as (slow==fast)
            }
        }
        return -1;
    }
};