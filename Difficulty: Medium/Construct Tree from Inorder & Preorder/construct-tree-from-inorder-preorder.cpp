//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    
    Node * solve(int in[],int inStart,int inEnd,int pre[],int preStart,int preEnd,unordered_map<int,int> &inMap){
        
        if(preStart>preEnd || inStart>inEnd){
            return NULL;
        }
        
        Node * root = new Node(pre[preStart]);
        
        int inRoot = inMap[root->data];
        int numsLeft = inRoot-inStart;
        
        root->left = solve(in,inStart,inRoot-1,pre,preStart+1,preStart+numsLeft,inMap);
        root->right = solve(in,inRoot+1,inEnd,pre,preStart+numsLeft+1,preEnd,inMap);
        return root;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        
        unordered_map<int,int> inMap;
        
        for(int i= 0; i<n;i++){
            inMap[in[i]] = i;
        }
        
        Node * ans = solve(in,0,n-1,pre,0,n-1,inMap);
        return ans;
    }
    
    
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends