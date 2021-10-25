#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        long long maxArea = 0;
        long long minHeight = 0;
        for(long long i=0;i<n;i++)
        {
            maxArea=max(maxArea,1*arr[i]);
            minHeight=arr[i];
            for(long long j=i+1;j<n;j++)
            {
                minHeight = min(arr[j],minHeight);
                maxArea = max(maxArea, minHeight*(j-i+1));
            }
        }
        return maxArea;
    }
};


// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
  // } Driver Code Ends
