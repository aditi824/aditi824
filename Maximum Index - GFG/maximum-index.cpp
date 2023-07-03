//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int maxIndexDiff(int arr[], int n) {
        vector<int>l(n);
        vector<int>r(n);
        l[0]=arr[0];
        
        for(int i=1;i<n;i++){
            l[i]=min(l[i-1],arr[i]);
        }
        r[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--){
            r[i]=max(r[i+1],arr[i]);
        }
        int i=0,j=0;
        int ans=INT_MIN;
        while(i<n&&j<n){
            if(l[i]<=r[j]){
                ans=max(ans,j-i);
                j++;
            }
            else i++;
        }
        return ans;
    }

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(a, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends