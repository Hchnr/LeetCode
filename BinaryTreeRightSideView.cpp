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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == NULL)
            return ans;
        
        deque<TreeNode*> q;
        q.push_back(root);
        while( !q.empty() ) {
            int n = q.size();
            for(int i=0; i<n; i ++) {
                TreeNode* tmp = q.front();
                q.pop_front();
                if(i == n-1)
                    ans.push_back(tmp->val);
                if(tmp->left)
                    q.push_back(tmp->left);
                if(tmp->right)
                    q.push_back(tmp->right);  
            }
        }
        return ans;
    }
};
