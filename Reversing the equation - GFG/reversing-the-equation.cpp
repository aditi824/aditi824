//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseEqn (string s)
        {
         
             string res = "";
            int n = s.length ();
            int i = n - 1;
        
            stack <char> st;
            
            // traversing the string in reverse
            while (i >= 0)
            {
                // we traversed the string in reverse and pushed the characters in the stack
                // this is basically equaivalent to 2 reversals. Hence, we get the 
                // numbers/variables in their correct order.
                // for eg, say we have 20
                // stack becomes: 0 2 <- top
                // now, pushing the number in our result, we'll have 20
                if (s[i] == '+' or s[i] == '-' or s[i] == '*' or s[i] == '/')
                {
                    while (!st.empty ())
                    {
                        res += st.top ();
                        st.pop ();
                    }
                    res += s[i];
                }
                else
                    st.push (s[i]);
                i--;
            }
            
            // appending the last number/variable if any
            while (!st.empty ())
            {
                res += st.top ();
                st.pop ();
            }
            
            return res;
           
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends