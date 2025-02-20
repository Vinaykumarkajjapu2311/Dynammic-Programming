#include<bits/stdc++.h>
using namespace std;
int memo(int ind,vector<int>&arr,vector<int>&dp)
{
	
	if(ind==0)return 0;
	if(dp[ind]!=-1)return dp[ind];
	int left=memo(ind-1,arr,dp)+abs(arr[ind]-arr[ind-1]);
	int right=INT_MAX;
	
	if(ind>1)
	{
		right=memo(ind-2,arr,dp)+abs(arr[ind]-arr[ind-2]);
		
	}
	return dp[ind]=min(left,right);
}
int tab(vector<int>&arr)
{
	int n=arr.size();
	vector<int>dp(n,0);
	dp[0]=0;
	
	for(int i=1;i<n;i++)
	{
		int fs=dp[i-1]+abs(arr[i]-arr[i-1]);
		
		int ss=INT_MAX;
		if(i>1)
		{
			ss=dp[i-2]+abs(arr[i]-arr[i-2]);
		}
		dp[i]=min(fs,ss);
	}
	return dp[n-1];
}
int solve(vector<int>&arr)
{
	int n=arr.size();
	int prev=0,prev2=0;
	
	for(int i=1;i<n;i++)
	{
		int fs=prev+abs(arr[i]-arr[i-1]);
		int ss=INT_MAX;
		if(i>1)
		{
			ss=prev2+abs(arr[i]-arr[i-2]);
		}
		int curr=min(fs,ss);
		prev2=prev;
		prev=curr;
	}
	return prev;
	
	
}
int main()
{
	int n;
	cin>>n;
	vector<int>arr(n);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	cout<<solve(arr)<<endl;
	return 0;
}
