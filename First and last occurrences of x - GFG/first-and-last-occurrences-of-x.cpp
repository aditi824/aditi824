//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    int bs1(int arr[], int n , int x){
        int l=0;int r=n-1;
        int ans=-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(arr[mid]==x){
                ans=mid;
                r=mid-1;
            }
            else if(arr[mid]>x)r=mid-1;
            else l=mid+1;
        }
        return ans;
    }
     int bs2(int arr[], int n , int x){
        int l=0;int r=n-1;
        int ans=-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(arr[mid]==x){
                ans=mid;
                l=mid+1;
            }
            else if(arr[mid]>x)r=mid-1;
            else l=mid+1;
        }
        return ans;
    }
    vector<int> find(int arr[], int n , int x )
    {
        vector<int>res;
        int first=bs1(arr,n,x);
        int second=bs2(arr,n,x);
        res.push_back(first);
        res.push_back(second);
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends