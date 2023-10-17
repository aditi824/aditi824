//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Back-end complete function Template for C++

class Solution{
public:
    //Function to find the transitive closure of a graph.
    vector<vector<int>> transitiveClosure(int N, vector<vector<int>> graph)
    {
        //creating a 2D vector to store the reachability matrix.
        vector<vector<int>> reach(N, vector<int>(N, -1));

        //initializing reachability matrix with the given graph.
        for(int i = 0;i < N;i++){
            for(int j = 0;j < N;j++){
                if(i == j)
                    reach[i][j] = 1;
                else
                    reach[i][j] = graph[i][j];
            }
        }

        //applying Floyd Warshall algorithm to find transitive closure.
        for(int k = 0;k < N;k++)
            for(int i = 0;i < N;i++)
                for(int j = 0;j < N;j++)
                    reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);

        //returning the reachability matrix.
        return reach;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> graph(N, vector<int>(N, -1));
        for(int i = 0;i < N;i++)
            for(int j=0;j<N;j++)
            cin>>graph[i][j];
        
        Solution ob;
        vector<vector<int>> ans = ob.transitiveClosure(N, graph);
        for(int i = 0;i < N;i++)
            {for(int j = 0;j < N;j++)
                cout<<ans[i][j]<<" ";
        cout<<"\n";}
    }
    return 0;
}
// } Driver Code Ends