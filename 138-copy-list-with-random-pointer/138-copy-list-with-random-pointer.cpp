/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return head;
        
        unordered_map<Node*,int> old;
        int i=0;
        Node *t=head;
        vector<Node*> newLL;
        while(t) {
            old[t]=newLL.size();
            Node *temp = new Node(t->val);
            newLL.push_back(temp);
            t=t->next;
        }
        Node* temp=head, *h=nullptr;
        for(int i=0 ; i<newLL.size() ; ++i) {
            if(i==0)
                h=newLL[i];
            else
                t->next=newLL[i];
            t=newLL[i];
            t->next = temp->next==nullptr ? temp->next : newLL[old[temp->next]];
            t->random = temp->random==nullptr ? temp->random : newLL[old[temp->random]];
            temp = temp->next;
        }
        return h;
    }
};