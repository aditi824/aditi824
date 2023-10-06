//{ Driver Code Starts
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/* A linked list node */


struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

struct Node *start = NULL;

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
    
}

void insert()
{
    int n,value;
    cin>>n;
    struct Node *temp;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            start = new Node(value);
            temp = start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
        }
    }
}


// } Driver Code Ends
/*
  reverse alternate nodes and append at the end
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
      int data;
      struct Node *next;
    
      Node(int x){
        data = x;
        next = NULL;
      }
    
   };

*/
class Solution
{
    public:
    void rearrange(struct Node *odd)
    {
        if (odd == NULL || odd->next == NULL || odd->next->next == NULL)
            // for less than 3 nodes, no rearrangement is required
            return;
        
        struct Node *even = odd->next;    // even points at the second node
        odd->next = odd->next->next;      // placing third node after first
        odd = odd->next;                  // odd now points to the third node
        even->next = NULL;                // placing NULL after second node
        
        while (odd && odd->next)
        {        
            struct Node *temp = odd->next->next;   // next odd node
            odd->next->next = even;       // connecting next even node to even
            even = odd->next;             // moving to next even node
            odd->next = temp;             // connecting odd to next odd node
            
            if (temp != NULL)
                odd = temp;
        }
        odd->next = even;
    }
};



//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while (t--) {
        insert();
        Solution ob;
        ob.rearrange(start);
        printList(start);
    }
    return 0;
}

// } Driver Code Ends