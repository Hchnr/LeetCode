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
    void invertTree(TreeNode* root) {
        if(root == NULL)
            return;
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        invertTree(root->left);
        invertTree(root->right);
    }
    
    bool equalTree(TreeNode* a, TreeNode* b) {
        if(a == NULL && b == NULL)
            return true;
        if(a == NULL || b == NULL)
            return false;
        if(a->val != b->val)
            return false;
        return (equalTree(a->left, b->left) &&
                equalTree(a->right, b->right));
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        invertTree(root->left);
        return equalTree(root->left, root->right);
    }
};
