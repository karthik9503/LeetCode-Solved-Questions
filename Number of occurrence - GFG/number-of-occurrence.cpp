//{ Driver Code Starts

#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    // code here
	    int firstacc=-1;
	    int s=0,end=n-1;
	    while(s<=end){
	        int mid=(s+end)/2;
	        if(arr[mid]==x){end=mid-1;firstacc=mid;}
	        if(arr[mid]>x){end=mid-1;}
	        if(arr[mid]<x){s=mid+1;}
	    }
	    s=0,end=n-1;
	    int secondacc=-1;
	    while(s<=end){
	        int mid=(s+end)/2;
	        if(arr[mid]==x){secondacc=mid;s=mid+1;}
	        if(arr[mid]>x){end=mid-1;}
	        if(arr[mid]<x){s=mid+1;}
	        
	    }
	    if(secondacc==-1){return 0;}
	    return (secondacc-firstacc+1);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends