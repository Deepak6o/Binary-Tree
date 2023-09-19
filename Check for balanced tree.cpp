
class Solution {
public:
    int height(TreeNode* root)
    {
        if(root==NULL)
        {
            return NULL;
        }
        int left=height(root->left);
        int right=height(root->right);
        int ans=max(left,right)+1;
        return ans;
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL)
        {
            return true;
        }
        bool left=isBalanced(root->left);
        bool right=isBalanced(root->right);
        bool diff = abs(height(root->left)-height(root->right))<=1;
        if(diff && left && right)
        {
            return true;
        }
        return false;
        
    }
};
