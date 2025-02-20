#include<bits/stdc++.h>
using namespace std;
//memoisation
int memo(int ind,vector<int>&arr,vector<int>&dp)
{
	if(ind==0)
	{
		return arr[ind];
	}
	if(ind<0)return 0;
	if(dp[ind]!=-1)return dp[ind];
	int take=arr[ind]+memo(ind-2,arr,dp);
	int nottake=0+memo(ind-1,arr,dp);
	return dp[ind]=max(take,nottake);
}
//tabulation
int tab(vector<int>&arr)
{
	int n=arr.size();
	vector<int>dp(n,-1);
	dp[0]=arr[0];
	dp[1]=max(arr[0],arr[1]);
	for(int i=2;i<n;i++)
	{
		int take=arr[i];
		take+=dp[i-2];
		int nottake=dp[i-1];
		
		dp[i]=max(take,nottake);
	}
	return dp[n-1];

}
//space optimization
int solve(vector<int>&arr)
{
	int n=arr.size();
	int prev=max(arr[0],arr[1]);
	int prev2=arr[0];
	
	for(int i=2;i<n;i++)
	{
		int take=arr[i]+prev2;
		int nottake=prev;
		
		int curr=max(take,nottake);
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
