//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    int binarysearch(vector<long long> v,long long l,long long r,long long x){
        if(r-l==1){
            if(v[r]>x){return l;}
            else{return r;}
        }
        else if(l<r){
            int m=(l+r)/2;
            if(v[m]==x){return m;}
            else if(v[m]>x){return binarysearch(v,l,m-1,x);}
            else{return binarysearch(v,m,r,x);}
        }
        return -1;
    }
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> v, long long n, long long x){
        
        // Your code here
        if(v[0]==x || v[0]>x){return -1;}
        int m=(n-1)/2;
        if(v[m]==x){return m;}
        else if(v[m]>x){return binarysearch(v,0,m-1,x);}
        else{return binarysearch(v,m,n-1,x);}
        return -1;
        
    }
};


//{ Driver Code Starts.

int main() {
	
	long long t;
	cin >> t;
	
	while(t--){
	    long long n;
	    cin >> n;
	    long long x;
	    cin >> x;
	    
	    vector<long long> v;
	    
	    for(long long i = 0;i<n;i++){
	        long long temp;
	        cin >> temp;
	        v.push_back(temp);
	    }
	    Solution obj;
	    cout << obj.findFloor(v, n, x) << endl;
	   
	}
	
	return 0;
}
// } Driver Code Ends