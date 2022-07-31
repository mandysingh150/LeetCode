class segment_tree {
public:
    int *a, original_array_size;
    
    segment_tree(int _size) {
        a = new int[4*_size];
        original_array_size = _size;
    }

    void build(vector<int> &v) {
        build_helper(0, v, 0, original_array_size-1);
    }

    void build_helper(int node, vector<int> &v, int si, int ei) {
        if(si>=ei) {
            if(si == ei) {
                a[node] = v[si];
            }
            return;
        }

        int mid = (si+ei)/2;
        
        // build the left child, from "si" to "mid"
        build_helper(2*node+1, v, si, mid);

        // build the right child, from "mid+1" to "ei"
        build_helper(2*node+2, v, mid+1, ei);

        // build the current node answer, a[node]
        a[node] = a[2*node+1] + a[2*node+2];
    }

    int query(int query_left, int query_right) {
        return query_helper(0, 0, original_array_size-1, query_left, query_right);
    }

    int query_helper(int node, int si, int ei, int query_left, int query_right) {
        if(ei<query_left or query_right<si) {
            // CASE 1: NO OVERLAP, return an impossible value
            return 0;
        }
        if(query_left<=si and ei<=query_right) {
            // CASE 2: COMPLETE OVERLAP, return current node's answer
            return a[node];
        }

        // CASE 3: PARTIAL OVERLAP, make answer from both children
        int mid = (si+ei)/2;

        int left_answer = query_helper(2*node+1, si, mid, query_left, query_right);
        int right_answer = query_helper(2*node+2, mid+1, ei, query_left, query_right);
        
        // make answer from "left_answer" and "right_answer" and then return it
        return left_answer + right_answer;
    }

    void update(int index, int value) {
        update_helper(0, 0, original_array_size-1, index, value);
    }

    void update_helper(int node, int si, int ei, int index, int value) {
        if(si == ei) {
            a[node] = value;
            return;
        }

        int mid = (si+ei)/2;
        
        (index <= mid) ? update_helper(2*node+1, si, mid, index, value) 
                        : update_helper(2*node+2, mid+1, ei, index, value);

        a[node] = a[2*node+1] + a[2*node+2];
    }
};

class NumArray {
public:
    segment_tree st;
    NumArray(vector<int>& nums) : st(nums.size()) {
        st.build(nums);
    }
    
    void update(int index, int val) {
        st.update(index, val);
    }
    
    int sumRange(int left, int right) {
        return st.query(left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */