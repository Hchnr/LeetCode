tion for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {

public:
    vector<int> preorderTraversal(TreeNode* root) {
        deque<TreeNode*> q;
        vector<int> ans;
        if(root == NULL)
            return ans;
        
        q.push_front(root);
        while(!q.empty()) {
            TreeNode* p = q.front();
            q.pop_front();
            /* output root first, then left all the way */
            ans.push_back(p->val);
            if(p->right) {
                q.push_front(p->right);
            }
            if(p->left) {
                q.push_front(p->left);
            }

        }
        return ans;
    }
};
