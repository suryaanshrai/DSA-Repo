// https://practice.geeksforgeeks.org/problems/maximum-index3307/1
//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{

public:
    int maxIndexDiff(int arr[], int n) {
        // code here
        vector<int> maxR(n), minL(n); // these two arrays will store the maximum number and minimum number till that point
        
        minL[0] = arr[0];
        for (int i = 1; i < n; i++) {
            minL[i] = min(minL[i-1], arr[i]);
        }
        
        maxR[n-1] = arr[n-1];
        for (int j = n-2; j >= 0; j--) {
            maxR[j] = max(maxR[j+1], arr[j]);
        }
        
        int i = 0, j = 0;
        int ans = -1;
        
        // We keep checking the condition and increasing the answer until we reach the best solution
        // This is a two pointer approach
        while (i < n && j < n) {
            if (minL[i] <= maxR[j]) {
                ans = max(ans, j-i);
                j++;
            }
            else {
                i++;
            }
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