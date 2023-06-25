//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col);


// } Driver Code Ends
class Solution
{
    public:
    // #define MAX 1000
    vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col)
    {
      set<string> st;
        vector<vector<int>> vec;
        
        for(int i=0;i<row;i++)
        {
            string curr;
            for (int j = 0;j < col;j++)
            {
                curr += '0' + M[i][j];
            }
            st.insert(curr);
        }
        for(int i=0;i<row;i++)
        {
            string curr;
            for (int j = 0;j < col;j++)
            {
                curr += '0' + M[i][j];
            }
            if (st.find(curr) != st.end())
            {
                st.erase(curr);
                vector<int> demo;
                for (int j = 0;j < col;j++)
                {
                    demo.push_back(M[i][j]);
                }
                vec.push_back(demo);
            }
        }
        return vec;
    }
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
    	int n,m;
    	cin>>n>>m;
    	int a[MAX][MAX];
    	for(int i=0;i<n;i++)
    	for(int j=0;j<m;j++)
    	cin>>a[i][j];
    	Solution ob;
    	vector<vector<int>> vec = ob.uniqueRow(a,n,m);
    	for(int i = 0;i<vec.size();i++){
    	    for(int x : vec[i]){
    	        cout<<x<<" ";
    	    }
    	    cout<<"$";
    	}
    	cout<<endl;
    }
}

// } Driver Code Ends