//{ Driver Code Starts
// Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    int findWays(vector<int> &arr, int i, int required_sum, int n, vector<vector<int>> &dp)
    {
        // Base case
        int MOD = 1e9 + 7;
        if(required_sum < 0) return  0;
        if (i == n) {
            if (required_sum == 0)
                return dp[i][required_sum] = 1;
            else
                return dp[i][required_sum] = 0;
        }
        
        // If the state has been solved before return the value of the state
        if (dp[i][required_sum] != -1) return dp[i][required_sum];
        
        // Recurrence relation
        dp[i][required_sum] = (findWays(arr, i + 1, required_sum, n, dp) + findWays(arr, i + 1, required_sum - arr[i], n, dp));
        dp[i][required_sum] %= MOD;
        return dp[i][required_sum];
    }
    int numOfWays(int n, int x)
    {
        vector<int> arr;
        for(int i=1;i<=n;i++) {
            int p = pow(i, x);
            if(p<=n) {
                arr.push_back(p);
            } else {
                break;
            }
        }
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        return findWays(arr,0,n,arr.size(), dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n, x;
        cin >> n >> x;
        Solution ob;
        cout<<ob.numOfWays(n, x)<<endl;
    }
    return 0;
}

// } Driver Code Ends