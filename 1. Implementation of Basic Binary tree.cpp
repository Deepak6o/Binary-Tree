#include<iostream>
#include<queue>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }

};
node *buildTree(node *root)
{
    cout<<"Enter the data :"<<endl;
    int data;
    cin>>data;
    root=new node(data);
    if(data==-1)
    {
        return NULL;
    }
    cout<<"Enter data for Inserting for left"<<endl;
    root->left=buildTree(root->left);
    cout<<"Enter data fro Inserting for right"<<endl;
    root->right=buildTree(root->right);
    return root;
}
void levelOrderTraversal(node *root)
{
    queue<node *>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        node *temp = q.front();

        q.pop();
        if(temp==NULL)
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout<<temp->data<<" ";
            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }
        }

    }
}
void InOrder(node *root)
{
    if(root==NULL)
    {
        return ;
    }
    InOrder(root->left);
    cout<<root->data<<" ";
    InOrder(root->right);
}
void PreOrder(node *root)
{
    if(root==NULL)
    {
        return ;
    }
     cout<<root->data<<" ";
    PreOrder(root->left);

    PreOrder(root->right);
}
void PostOrder(node *root)
{
    if(root==NULL)
    {
        return ;
    }

    PostOrder(root->left);
    PostOrder(root->right);
    cout<<root->data<<" ";
}


int main()
{
    node *root=NULL;
    root = buildTree(root);
    cout<<"Printing the level order traversal output "<<endl;
    levelOrderTraversal(root);
    cout<<endl;
    cout<<"Printing the Inorder traversal output "<<endl;
    InOrder(root);
    cout<<endl;
    cout<<"Printing the Preorder traversal output "<<endl;
    PreOrder(root);
    cout<<endl;
    cout<<"Printing the Postorder traversal output "<<endl;
    PostOrder(root);
    return 0;
}

