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
    vector<string> ans;
    void traverse(TreeNode* root, string str) {
        if( !root )
            return;
        str += "->";
        str += std::to_string( root->val );
        if(root->left == NULL && root->right == NULL)
            ans.push_back(str);
        traverse(root->left, str);
        traverse(root->right, str);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        ans.clear();
        if( !root )
            return ans;
        string str;
        str = std::to_string( root->val );
        traverse(root->left, str);
        traverse(root->right, str);
        if(root->left == NULL && root->right == NULL)
            ans.push_back(str);
        return ans;
    }
};
