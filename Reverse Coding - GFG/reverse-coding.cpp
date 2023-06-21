//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
 
    int sumOfNaturals(int n) {
        int MOD = 1e9 + 7;
        long long sum = (((long long)n*(n+1))/2)%MOD;   // Computing (n*(n+1))/2
        
        return (int)sum;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        cout << ob.sumOfNaturals(n) << endl;
    }
    return 0;
}
// } Driver Code Ends