class Solution {
public:
    void TraversalLeft(Node* root,vector<int> &ans)
    {
        if((root==NULL) or (root->left==NULL and root->right==NULL))
        {
            return ;
        }
        ans.push_back(root->data);
        
            if(root->left)
            {
                TraversalLeft(root->left,ans);
            }
            else
            {
                TraversalLeft(root->right,ans);
            }
        
    }
    void TraversalLeaf(Node *root ,vector<int> &ans)
    {
        if(root==NULL)
        {
            return ;
        }
        if(root->left==NULL and root->right==NULL)
        {
            ans.push_back(root->data);
            return ;
        }
        TraversalLeaf(root->left,ans);
        TraversalLeaf(root->right,ans);
    }
    void TraversalRight(Node *root,vector<int> & ans)
    {
         if((root==NULL) or (root->left==NULL and root->right==NULL))
        {
            return ;
        }
        if(root->right)
        {
            TraversalRight(root->right,ans);
        }
        else
        {
            TraversalRight(root->left,ans);
        }
        ans.push_back(root->data);
        
    }
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int> ans;
        
        if(root==NULL)
        {
            return ans;
        }
        ans.push_back(root->data);
        // Left part Print
        TraversalLeft(root->left,ans);
        // left subree leaf
        TraversalLeaf(root->left,ans);
        //Right subtee
        TraversalLeaf(root->right,ans);
        
        //Right Part print
        TraversalRight(root->right,ans);
        return ans;
    }
};
