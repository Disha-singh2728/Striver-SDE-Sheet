// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
     // step-1 find nearest smallest to left index
     // step-2 find nearest smallest to right index
     // step-3 calculate width=right-left-1
     // step-4 calculate area=width*height heights are given
     // step-5 return max of areas
     vector<long long> left;
     vector<long long> right;
     stack<pair<long long,long long>> s;
     long long pseudo_left=-1;
     for(int i=0;i<n;i++)
     {
       if(s.empty()) left.push_back(pseudo_left);
       else if(s.size()>0 && s.top().first<arr[i])
       left.push_back(s.top().second); 
       else
       {
         while(!s.empty() && s.top().first>=arr[i])
           s.pop();
         if(s.empty()) left.push_back(pseudo_left);
         else  left.push_back(s.top().second);  
       }
      s.push({arr[i],i});
     }
     stack<pair<long long,long long>> s1;
     long long pseudo_right=n;
     for(int i=n-1;i>=0;i--)
     {
       if(s1.empty()) right.push_back(pseudo_right);
       else if(s1.size()>0 && s1.top().first<arr[i])
        right.push_back(s1.top().second); 
       else
       {
         while(!s1.empty() && s1.top().first>=arr[i])
           s1.pop();
         if(s1.empty()) right.push_back(pseudo_right);
         else  right.push_back(s1.top().second);  
     

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
