//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX],int n,int m,int k)
    {
 		int row=0,rowe=n-1,col=0,cole=m-1;
 		vector<int>v;
 		while(true){
 		for(int j=col;j<=cole;j++){
 		    v.push_back(a[row][j]);
 		}
 	
 		if(++row>rowe)break;
 		for(int i=row;i<=rowe;i++){
 		    v.push_back(a[i][cole]);
 		}
 	
 		if(--cole<col)break;
 		for(int j=cole;j>=col;j--){
 		    v.push_back(a[rowe][j]);
 		}
 	
 		if(--rowe<row)break;
 		for(int i=rowe;i>=row;i--){
 		    v.push_back(a[i][col]);
 		}
        
 		if(++col>cole)break;
 		}
 		return v[k-1];
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
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends