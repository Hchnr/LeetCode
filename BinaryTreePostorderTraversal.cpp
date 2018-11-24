/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL)
            return ans;
        
        deque<TreeNode*> q;
        deque<int> qq;
        q.push_front(root);
        qq.push_front(0);
        
        while(!q.empty()) {
            TreeNode* tmp = q.front();
            int op = qq.front();
            if(op == 0) {
                qq.pop_front();
                qq.push_front(1);
                if(tmp->left) {
                    q.push_front(tmp->left);
                    qq.push_front(0);
                }
                continue;
            }
            if(op == 1) {
                qq.pop_front();
                qq.push_front(2);               
                if(tmp->right) { 
                    q.push_front(tmp->right);
                    qq.push_front(0);
                }
                continue;
            }
            if(op == 2) {
                ans.push_back(tmp->val);
                q.pop_front();
                qq.pop_front();
            }
        }
        return ans;
    }
};
