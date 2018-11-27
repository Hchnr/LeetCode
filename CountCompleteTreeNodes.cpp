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
    int getHeight(TreeNode* root) {
        int ans = 0;
        while(root) {
            ans ++;
            root = root->left;
        }
        return ans;
    }
public:
    int countNodes(TreeNode* root) {
        int ans = (1 << getHeight(root)) - 1;
        int unit = 1 << (getHeight(root) - 2);
        while(root != NULL) {
            if(getHeight(root->left) != getHeight(root->right)) {
                ans -= unit;
                root = root->left;
            }
            else {
                root = root->right;
            }
            unit /= 2;
            if(getHeight(root) == 1)
                break;
        }
        return ans;
    }
};
