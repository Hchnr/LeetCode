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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL)
            return ans;
        
        deque<TreeNode*> q;
        q.push_back(root);
        while(!q.empty()) {
            int n = q.size();
            vector<int> a;
            for(int i=0; i<n ; i++) {
                a.push_back(q.front()->val);
                if(q.front()->left)
                    q.push_back(q.front()->left);   
                if(q.front()->right)
                    q.push_back(q.front()->right);  
                q.pop_front();
            }
            ans.push_back(a);
        }
        return ans;
    }
};
