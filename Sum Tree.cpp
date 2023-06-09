class Solution
{
    public:
    int isSum(Node *root)
    {
        if(root==NULL)
        {
            return 0;
        }
        if(root->left==NULL and root->right==NULL)
        {
            return root->data;
        }
        int left=isSum(root->left);
        int right=isSum(root->right);
        if(left==-1 or right ==-1)
        {
            return -1;
        }
        if(root->data==left+right)
        {
            return root->data+left+right;
        }
        return -1;
        
        
    }
    bool isSumTree(Node* root)
    {
         // Your code here
         if(isSum(root)==-1)
         {
             return false;
         }
         return true;
         
    }
};
