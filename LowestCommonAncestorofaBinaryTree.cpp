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
    bool find(TreeNode* root, TreeNode* p) {
        if(root == NULL)
            return false;
        if(root->val == p->val)
            return true;
        return find(root->left, p) || find(root->right, p);
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = root;
        if(root == NULL)
            return ans;
        
        while(1) {
            if(find(ans->left, p) && find(ans->left, q)) {
                ans = ans->left;
                continue;
            }
            if(find(ans->right, p) && find(ans->right, q)) {
                ans = ans->right;
                continue;
            }
            break;
        }
        return ans;
    }
};
