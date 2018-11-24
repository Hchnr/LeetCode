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
    int ans;
    void traverse(TreeNode* root, int sum) {
        if(root == NULL)
            return;
        if(root->left) {
            traverse(root->left, sum*10 + root->val);
        }
        if(root->right) {
            traverse(root->right, sum*10 + root->val);
        }
        if(root->left == NULL && root->right == NULL)
            ans += (sum*10) + root->val;
    }
public:
    int sumNumbers(TreeNode* root) {
        ans = 0;
        if(root == NULL)
            return ans;
        traverse(root, ans);
        return ans;
    }
};
