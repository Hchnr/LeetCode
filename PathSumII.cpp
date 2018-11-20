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
    vector<int> a;
    void find(TreeNode* root, int sum, vector<vector<int>> &arr) {
        if(root == NULL)
            return;
        a.push_back(root->val);
        if(root->left == NULL && root->right == NULL) {
            if(root->val == sum) 
                arr.push_back(a);
            a.pop_back();
            return;
        }
        find(root->left, sum - root->val, arr);
        find(root->right, sum - root->val, arr);
        a.pop_back();
        return;
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector< vector<int> > ans;
        find(root, sum, ans);
        return ans;
    }
};


