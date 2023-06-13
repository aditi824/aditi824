//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	vector<int> kLargest(int arr[], int n, int k) {
	  priority_queue<int,vector<int>,greater<int>>mq;
	  int i=0;
	  while(i<n){
	      mq.push(arr[i]);
	      if(mq.size()>k)mq.pop();
	     i++; 
	  }
	  vector<int>ans;
	  while(k){
	      ans.push_back(mq.top());
	      mq.pop();
	      k--;
	  }
	  sort(ans.begin(),ans.end(),greater<int>());
	  return ans;
	  }

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.kLargest(arr, n, k);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends