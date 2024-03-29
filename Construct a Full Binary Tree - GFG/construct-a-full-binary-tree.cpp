//{ Driver Code Starts
//Initial Template for C++
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


// } Driver Code Ends
/* Structre of the Node of the Binary Tree is as follows
struct Node
{
        int data;
        struct Node *left, *right;
};
*/
// your task is to complete this function
// function should create a new binary tree
// function should return the root node to the 
// new binary tree formed
class Solution{
  public:
    Node* constructBinaryTreeUtil(int pre[], int preM[], int &preIndex, int l,int h,int size)
    {
    	if (preIndex >= size || l > h)
    		return NULL;
    	Node* root = new Node(pre[preIndex]);
    	++(preIndex);
    	if (l == h)	return root;
    	int i;
    	for (i = l; i <= h; ++i)if (pre[preIndex] == preM[i])break;
    	if (i <= h)
    	{
    		root->left = constructBinaryTreeUtil (pre, preM, preIndex, i, h, size);
    		root->right = constructBinaryTreeUtil (pre, preM, preIndex, l+1, i-1, size);
    	}
    	return root; 
    }
    Node* constructBinaryTree(int pre[], int preMirror[], int size)
    {
        // Code here
    	int preIndex = 0;
    	int preMIndex = 0;
    	Node *root = constructBinaryTreeUtil(pre, preMirror, preIndex, 0, size-1, size);
    	return root;
    }
};

//{ Driver Code Starts.

void printInorder(Node* node)
{
	if (node == NULL)return;
	printInorder(node->left);
	cout<<node->data<<" ";
	printInorder(node->right);
}

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int preOrder[n];
	    int preOrderMirror[n];
	    for(int i=0; i<n; i++)cin>>preOrder[i];
	    for(int i=0; i<n; i++)cin>>preOrderMirror[i];
	    Solution obj;
	    printInorder(obj.constructBinaryTree(preOrder, preOrderMirror, n));
	    cout<<endl;
    }
	return 0;
}
// } Driver Code Ends