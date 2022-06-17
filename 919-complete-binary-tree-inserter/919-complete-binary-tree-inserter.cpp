/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class CBTInserter {
public:
    TreeNode *root;
    int total_nodes;
    
    void dfs(TreeNode *t) {
        if(t) {
            total_nodes++;
            dfs(t->left);
            dfs(t->right);
        }
    }
    
    CBTInserter(TreeNode* root) {
        this->root = root;
        total_nodes = 0;
        dfs(this->root);
    }
    
    int insert(int val) {
        ++total_nodes;
        
        int in=31, n=total_nodes;
        while((n&(1<<in)) == 0) {
            in--;
        }
        in--;
        TreeNode *t=root, *prev=nullptr;
        while(in > 0) {
            prev = t;
            t = ((n&(1<<in)) ? t->right : t->left);
            in--;
        }
        prev = t;
        ((n&1)==0 ? t->left : t->right) = new TreeNode(val);
        return prev->val;
    }
    
    TreeNode* get_root() {
        return root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */