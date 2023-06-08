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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL and q==NULL)
        {
            return true;
        }
        if(p==NULL or q==NULL)
        {
            return false;
        }
        bool left = isSameTree(p->left,q->left);
        bool right = isSameTree(p->right,q->right);
        bool currVal= p->val==q->val;
        if(currVal && left && right)
        {
            return true;
        }
        return false;
        
    }
};
