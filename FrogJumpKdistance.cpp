#include<bits/stdc++.h>
using namespace std;

///memoization
int memo(int ind,vector<int>&dp,vector<int>&arr,int k)
{
	if(ind==0)return 0;
	
	if(dp[ind]!=-1)return dp[ind];
	int miniSteps=INT_MAX;
	for(int j=1;j<=k;j++)
	{
		if(ind-j>=0)
		{
			int jump=memo(ind-j,dp,arr,k)+abs(arr[ind]-arr[ind-j]);
			miniSteps=min(miniSteps,jump);
		}
		else
		{
			break;
		}
	}
	return dp[ind]=miniSteps;
}

//tabulation
int solve(vector<int>&arr,int k)
{
	int n=arr.size();
	vector<int>dp(n,0);
	
	for(int i=1;i<n;i++)
	{
		int miniSteps=INT_MAX;
		for(int j=1;j<=k;j++)
		{
			if(i-j>=0)
			{
				int jump=dp[i-j]+abs(arr[i]-arr[i-j]);
				miniSteps=min(miniSteps,jump);
			}
			else
			break;
		}
		dp[i]=miniSteps;
	}
	return dp[n-1];
	
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
	int k;
	cin>>k;
	
	cout<<solve(arr,k)<<endl;
}
