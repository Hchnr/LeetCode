/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL)
            return;
        
        vector<TreeLinkNode*> q;
        q.push_back(root);
        
        while(!q.empty()) {
            for(int i=0; i < q.size()-1; i++)
                q[i]->next = q[i+1];
            q[q.size()-1]->next = NULL;
            vector<TreeLinkNode*> tmp;
            for(int i=0; i < q.size(); i++) {
                if(q[i]->left)
                    tmp.push_back(q[i]->left);
                if(q[i]->right)
                    tmp.push_back(q[i]->right);
            }
            q.clear();
            q = tmp;
        }
    }
};
