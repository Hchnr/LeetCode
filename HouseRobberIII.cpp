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
    int rob(TreeNode* root) {
        if( !root )
            return 0;
        int notthis = rob(root->left) + rob(root->right);
        int bethis = root->val;
        if(root->left)
            bethis += rob(root->left->left) + rob(root->left->right);
        if(root->right)
            bethis += rob(root->right->left) +  rob(root->right->right);
        return (notthis > bethis)? notthis: bethis;
    }
};
