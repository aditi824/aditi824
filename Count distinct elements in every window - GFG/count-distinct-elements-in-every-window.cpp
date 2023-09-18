//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution{
  public:
    vector <int> countDistinct (int a[], int n, int k)
    {
       int i=0,j=0;
       map<int,int>m;
       vector<int>ans;
       while(i<n&&j<n){
          m[a[j]]++;
          if(j-i+1==k){
              ans.push_back(m.size());
              m[a[i]]--;
              if(m[a[i]]==0)m.erase(a[i]);
              i++;
          }
          j++;
       }
       return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) 
        	cin >> a[i];
        Solution obj;
        vector <int> result = obj.countDistinct(a, n, k);
        for (int i : result) 
        	cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends