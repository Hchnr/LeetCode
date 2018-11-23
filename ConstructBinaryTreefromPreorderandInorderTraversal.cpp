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
    void buildTree(vector<int>::iterator pl, vector<int>::iterator pr,
                   vector<int>::iterator il, vector<int>::iterator ir,
                   TreeNode* &root) {
        if(pl == pr || il == ir)
            return;
        root = new TreeNode(*pl);
        vector<int>::iterator in_left_end = find( il, ir, *pl );
        vector<int>::iterator in_right_begin = in_left_end + 1;
        vector<int>::iterator pre_left_end = pl + (in_left_end - il) + 1;
        vector<int>::iterator pre_right_begin = pre_left_end;
        buildTree(pl+1, pre_left_end, il, in_left_end, root->left);
        buildTree(pre_right_begin, pr, in_right_begin, ir, root->right);
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* ans = NULL;
        buildTree(preorder.begin(), preorder.end(), inorder.begin(), inorder.end(), ans);
        return ans;
    }
};
