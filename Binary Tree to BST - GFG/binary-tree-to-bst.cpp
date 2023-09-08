//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; 

void printInorder (struct Node* node)
{
    if (node == NULL)
    return;

    printInorder (node->left);
    printf("%d ", node->data);
    printInorder (node->right);
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
    Node *root = new Node(stoi(ip[0]));

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

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));


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
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    return root;
}

// } Driver Code Ends
//User function template for C++

/* The Node structure is
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; 
*/


class Solution{
  public:
    
    void getArr(int arr[], int *index, Node *root)
    {
        if(root == NULL)
            return ;
        
        getArr(arr, index, root->left);
        
        arr[*index] = root->data;
        *index += 1;
        
        getArr(arr, index, root->right);
    }
    
    
    void convert(Node *root, int arr[], int *index)
    {
        if(root == NULL)
            return ;
    
        convert(root->left, arr, index);
        
        root->data = arr[*index];
        *index += 1;
        
        convert(root->right, arr, index);
    }
    
    int totalNodes(Node* root)
    {
        if(root == NULL)
            return 0;
        
        return (1 + totalNodes(root->left) + totalNodes(root->right));
    }
    
    Node* binaryTreeToBST (Node *root)
    {
        if(root == NULL)
            return NULL ;
        
        int n = totalNodes(root);
        
        int *arr = new int[n + 1];
        
        int index = 0;

        getArr(arr, &index, root);
        
        sort(arr, arr + index);
        
        index = 0;
        
        convert(root, arr, &index);
        
        return root;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    scanf("%d\n", &t);
    while (t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        Solution obj;
        Node *res = obj.binaryTreeToBST (root);
        printInorder(res);
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends