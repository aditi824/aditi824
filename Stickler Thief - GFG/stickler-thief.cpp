//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int solve(int arr[], int n,int i,vector<int>&dp){
        if(i>n-1)return 0;
        if(dp[i]!=-1)return dp[i];
        int pick=arr[i]+solve(arr,n,i+2,dp);
        int notpick=solve(arr,n,i+1,dp);
        return dp[i]=max(pick,notpick);
    }
    int FindMaxSum(int arr[], int n)
    {   vector<int>dp(n+1,-1);
        return solve(arr,n,0,dp);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends