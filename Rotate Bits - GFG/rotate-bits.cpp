//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define SHORT_SIZE 16
class Solution {
public:
    vector<int> rotate(int n, int d)
    {
        // rotation of 16 is same as rotation of 0
        // rotation of 17 is same as rotation of 1
        // and so on.
        d = d % 16;
        vector<int> res(2);

        string s = "";
        for (int i = 15; i >= 0; i--) {
            if (n & (1 << i)) {
                s += '1';
            }
            else {
                s += '0';
            }
        }

        string l = "";

        for (int i = d; i < 16; i++) {
            l += s[i];
        }

        for (int i = 0; i < d; i++) {
            l += s[i];
        }

        string r = "";

        for (int i = 16 - d; i < 16; i++) {
            r += s[i];
        }

        for (int i = 0; i < 16 - d; i++) {
            r += s[i];
        }

        int l1 = 0, r1 = 0;

        for (int i = 0; i < 16; i++) {

            if (l[i] == '1') {
                l1 += (1 << (15 - i));
            }

            if (r[i] == '1') {
                r1 += (1 << (15 - i));
            }
        }

        res[0] = l1, res[1] = r1;

        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        
        int n, d; cin >> n >> d;
        Solution ob;
        vector <int> res = ob.rotate (n, d);
        cout << res[0] << endl << res[1] << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends