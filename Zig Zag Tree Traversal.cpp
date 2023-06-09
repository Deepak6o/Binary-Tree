class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	vector<int> result;
    	if(root==NULL)
    	{
    	    return result;
    	}
    	queue<Node *>q;
    	q.push(root);
    	bool LefttoRightFlag=true;
    	while(!q.empty())
    	{
    	    int size=q.size();
    	    vector<int> ans(size);
    	    // Level Process
    	    for(int i=0;i<size;i++)
    	    {
    	        Node *temp=q.front();
    	        q.pop();
                // Normal insert or Reverse Insert
    	        int index = LefttoRightFlag ? i : size-i-1;
    	        ans[index]=temp->data;
    	        
    	        if(temp->left)
    	        {
    	            q.push(temp->left);
    	        }
    	        if(temp->right)
    	        {
    	            q.push(temp->right);
    	        }
    	    }
    	    // Direction Change
    	    LefttoRightFlag=!LefttoRightFlag;
    	    for(auto x: ans)
    	    {
    	        result.push_back(x);
    	    }
    	}
    	return result;
    }
};
