/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
vector<vector<int>> levelOrder(TreeNode* root,vector<vector<int>> &ans) {
        if(root==NULL)
        {
            return {};
        }
        
        queue<TreeNode *> q;
        q.push(root);
        TreeNode *temp;
        int len;
        while(!q.empty())
        {
            len=q.size();
            vector<int>v;
            for(int i=0;i<len;i++)
            {
                temp=q.front();
                q.pop();
                v.push_back(temp->val);
                if(temp->left)
                {
                    q.push(temp->left);
                }
                if(temp->right)
                {
                    q.push(temp->right);
                }
            }
            ans.push_back(v);
        }
        return ans;
        
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL)
        {
            return {};
        }
        levelOrder(root,ans);
        reverse(ans.begin(),ans.end());
        return ans;
        
        
    }
};
