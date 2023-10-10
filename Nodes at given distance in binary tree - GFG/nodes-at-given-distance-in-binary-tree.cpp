//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
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
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution
{
private:
    vector <int> v;

    void findKDistanceDownNode(Node *root, int k)
    /* Recursive function to find all the nodes at distance k in the
       tree (or subtree) rooted with given root. See  */
    {
        // Base Case
        if (root == NULL || k < 0)  return;
    
        // If we reach a k distant node, add to vector
        if (k==0)
        {
            v.push_back(root->data);
            return;
        }
    
        // Recur for left and right subtrees
        findKDistanceDownNode(root->left, k-1);
        findKDistanceDownNode(root->right, k-1);
    }
    
    int findKDistanceNode(Node* root, int target , int k)
    // Finds all nodes at distance k from a given target node.
    // The k distant nodes may be upward or downward.  This function
    // Returns distance of root from target node, it returns -1 if target
    // node is not present in tree rooted with root.
    {
        // Base Case 1: If tree is empty, return -1
        if (root == NULL) return -1;
        
        // If target is same as root.  Use the downward function
        // to find all nodes at distance k in subtree rooted with
        // target or root
        if (root->data == target)
        {
            findKDistanceDownNode(root, k);
            return 0;
        }
        
        // Recur for left subtree
        int dl = findKDistanceNode(root->left, target, k);
        
        // Check if target node was found in left subtree
        if (dl != -1)
        {
             // If root is at distance k from target, add root value to vector
             // Note that dl is Distance of root's left child from target
             if (dl + 1 == k)
                v.push_back(root->data);
            
             // Else go to right subtree and print all k-dl-2 distant nodes
             // Note that the right child is 2 edges away from left child
             else
                findKDistanceDownNode(root->right, k-dl-2);
            
             // Add 1 to the distance and return value for parent calls
             return 1 + dl;
        }
        
        // MIRROR OF ABOVE CODE FOR RIGHT SUBTREE
        // Note that we reach here only when node was not found in left subtree
        int dr = findKDistanceNode(root->right, target, k);
        if (dr != -1)
        {
             if (dr + 1 == k)
                v.push_back(root->data);
             else
                findKDistanceDownNode(root->left, k-dr-2);
             return 1 + dr;
        }
        
        // If target was neither present in left nor in right subtree
        return -1;
    }

public:

    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        v.clear();
        
        findKDistanceNode(root, target, k);
        
        sort( v.begin(), v.end() );
        
        return v;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    Solution x = Solution();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends