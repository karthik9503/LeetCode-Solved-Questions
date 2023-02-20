//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

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
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends

int binarysearch(int arr[],int l,int r,int x){
    if(r>=l){
        int m=(r+l)/2;
        if(arr[m]==x){return m;}
        else if(arr[m]<x){return binarysearch(arr,m+1,r,x);}
        else{return binarysearch(arr,l,m-1,x);}
    }
    return -1;
}
pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    // code here
    arr[n]=x;
    int ans;
    sort(arr,arr+n+1);
    int m=n/2;
    if(arr[m]==x){ans=m;}
    else if(arr[m]<x){ans= binarysearch(arr,m+1,n,x);}
    else{ans= binarysearch(arr,0,m-1,x);}
    if(ans==n){if(arr[n-1]==x){return make_pair(x,x);}
        else{return make_pair(arr[n-1],-1);}}
    else if(ans==0){if(arr[1]==x){return make_pair(x,x);}
        else{return make_pair(-1,arr[1]);}}
    else{if(arr[ans+1]==x || arr[ans-1]==x){return make_pair(x,x);}
        else{return make_pair(arr[ans-1],arr[ans+1]);}}
    return make_pair(-1,-1);
    
}