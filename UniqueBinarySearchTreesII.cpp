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
    vector<TreeNode*> generateTrees(int l, int r) {
        vector<TreeNode*> ans;
        if(l > r) {
            ans.push_back(NULL);
            return ans;
        }
        
        for(int i=l; i<=r; i++) {
            vector<TreeNode*> lt = generateTrees(l, i-1);
            vector<TreeNode*> rt = generateTrees(i+1, r);
            for(int j=0; j<lt.size(); j++)
                for(int k=0; k<rt.size(); k++) {
                    TreeNode* root = new TreeNode(i);
                    root->left = lt[j];
                    root->right = rt[k];
                    ans.push_back(root);
                }
        }
        return ans;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ans;
        if(n == 0)
            return ans;
        
        ans = generateTrees(1, n);
        return ans;
    }
};
