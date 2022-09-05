/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> v;
        vector<int> t;
        queue<Node*> q;
        if(!root) return v;
        q.push(root);
        q.push(nullptr);
        while(!q.empty()) {
            auto top = q.front();
            q.pop();
            
            if(top == nullptr) {
                v.push_back(t);
                if(q.empty()) break;
                t.clear();
                q.push(nullptr);
                top=q.front();
                q.pop();
            }
            t.push_back(top->val);
            for(auto i: top->children) q.push(i);
        }
        return v;
    }
};