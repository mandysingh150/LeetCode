class NumArray {
    inline static int n;
public:
    vector<int> tree;
    NumArray(vector<int>& nums) {
        n = nums.size();
        tree = vector<int>(nums.size()*4);
        build(nums, 1, 0, n-1);
    }
    
    void build(vector<int> &a, int node, int si, int ei) {
        if(si == ei)
            tree[node] = a[si];
        else {
            int mid = (si+ei)/2;
            build(a, 2*node, si, mid);
            build(a, 2*node+1, mid+1, ei);
            tree[node] = tree[2*node] + tree[2*node+1];
        }
    }
    
    void update(int index, int val, int node=1, int si=0, int ei=n-1) {
        if(si==ei)
            tree[node] = val;
        else {
            int mid = (si+ei)/2;
            if(index<=mid) 
                update(index, val, 2*node, si, mid);
            else
                update(index, val, 2*node+1, mid+1, ei);
            tree[node] = tree[2*node] + tree[2*node+1];
        }
    }
    
    int sumRange(int left, int right, int node=1, int si=0, int ei=n-1) {
        if(left > right)
            return 0;
        if(left<=si and ei<=right)
            return tree[node];
        
        int mid = (si+ei)/2;
        return sumRange(left, min(right, mid), 2*node, si, mid) + 
                sumRange(max(mid+1, left), right, 2*node+1, mid+1, ei);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */