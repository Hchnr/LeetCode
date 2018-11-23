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
    int deep = 0;
    int find_deep(TreeNode* root) {
        if(root == NULL)
            return deep;
        deep ++;
        int l = find_deep(root->left);
        int r = find_deep(root->right);
        deep --;
        return  (l > r)? l: r;
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
            return true;
        if( abs( find_deep(root->left) - find_deep(root->right) ) > 1 )
            return false;
        return (isBalanced(root->left) && isBalanced(root->right) );
    }
};
