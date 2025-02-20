#include<bits/stdc++.h>
using namespace std;
//memoization
int memo(int n,vector<int>&dp)
{
	if(n<=1)return n;
	
	if(dp[n]!=-1)return dp[n];
	
	return dp[n]=memo(n-1,dp)+memo(n-2,dp);
	
}
//tabulation
int tab(int n)
{
	vector<int>dp(n+1,0);
	dp[0]=0;
	dp[1]=1;
	
	for(int i=2;i<=n;i++)
	{
		dp[i]=dp[i-1]+dp[i-2];
	}
	return dp[n];
	
}

//space optimization
int solve(int n)
{
	int prev2=0,prev=1;
	for(int i=2;i<=n;i++)
	{
		int curr=prev+prev2;
		prev2=prev;
		prev=curr;
	}
	return prev;
}
int main()
{
	int n;
	cin>>n;
	
	cout<<solve(n)<<endl;
	return 0;
}
