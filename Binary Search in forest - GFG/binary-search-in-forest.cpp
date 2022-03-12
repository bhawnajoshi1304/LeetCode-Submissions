// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    int find_height(int tree[], int n, int k)
    {
        sort(tree,tree+n);
        for(int i=n-2;i>=0;i-=1)
        tree[i]+=tree[i+1];
        for(int i=0;i<n;i+=1){
            int tmp=(tree[i]-k)%(n-i),x=(tree[i]-k)/(n-i);
            if(tmp==0){
                if(i==0 && x>=0 &&x<=tree[i]-tree[i+1])
                return x;
                else if(i==n-1 && x<=tree[i] && x>=tree[i-1]-tree[i])
                return x;
                else if(x<=tree[i]-tree[i+1] && x>=tree[i-1]-tree[i])
                return x;
            }
        }
        return -1;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n;

        int tree[n];
        for(int i=0; i<n; i++)
            cin>>tree[i];
        cin>>k;
        Solution ob;
        cout<< ob.find_height(tree,n,k) << endl;
    }
    return 1;
}  // } Driver Code Ends