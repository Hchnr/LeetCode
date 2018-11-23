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
    void buildTree(vector<int>::iterator in_begin, vector<int>::iterator in_end,
                   vector<int>::iterator post_begin, vector<int>::iterator post_end,
                   TreeNode* &root) {
        if(in_begin == in_end || post_begin == post_end)
            return;
        root = new TreeNode(*(post_end - 1));
        vector<int>::iterator in_left_end = find( in_begin, in_end, *(post_end - 1) );
        vector<int>::iterator in_right_begin = in_left_end + 1;
        vector<int>::iterator post_left_end = post_begin + (in_left_end - in_begin);
        vector<int>::iterator post_right_begin = post_left_end;
        buildTree(in_begin, in_left_end, post_begin, post_left_end, root->left);
        buildTree(in_right_begin, in_end, post_right_begin, (post_end - 1), root->right);
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode* ans = NULL;
        buildTree(inorder.begin(), inorder.end(), postorder.begin(), postorder.end(), ans);
        return ans;
       
    }
};
