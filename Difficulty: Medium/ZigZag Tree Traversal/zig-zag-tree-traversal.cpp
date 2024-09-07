//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++
/*Structure of the node of the binary tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	
    	vector<int > result;
    	
    	if(root == NULL){
    	    return result;
    	}
    	
    	queue<Node *> q;
    	
    	q.push(root);
    	bool leftToRight = true;// we are using a flag variable such that when it  is true we will push the elements into the ans vector into left ot right direction.
    	
    	// And when it is set false we will push the elements into the vector from right to left.
    	
    	//After each level the flag value is change from true to false and from false to true.
    	
    	//The code is pretty much same as that of level order traversal with a little modification of flag and how we push the elements into the answer vector.
    
    
    	
    	while(!q.empty()){
    	    
    	    int size = q.size();
    	    vector<int> ans(size);
    	   
    	   for(int i= 0 ; i<ans.size();i++){
    	       
    	       Node * element = q.front();
    	       q.pop();
    	       
    	       int index;
    	       
    	       if(leftToRight){
    	           index = i;
    	       }
    	       
    	       else{
    	           index = size-i-1;
    	       }
    	       
    	       ans[index] = element->data;
    	   
    	   
    	    if(element->left){
    	        q.push(element->left);
    	    }
    	    
    	    if(element->right){
    	        q.push(element->right);
    	    }
    	   }
    	   
    	   leftToRight = !leftToRight;
    	  result.insert(result.end(),ans.begin(),ans.end());
    	   } 
    	   
    	  
    	    
    	    return result;
    	    
    	}
    	
    };
    


//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);

        vector<int> ans;
        Solution ob;
        ans = ob.zigZagTraversal(root) ;

        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";

        cout << endl;
     
    }
    return 0;
}

// } Driver Code Ends