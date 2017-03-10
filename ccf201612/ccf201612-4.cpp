#include <iostream>
#include <cstdio>

#define N 1005
#define INF 0x7fffffff

using namespace std;

int dp[N][N];
int sum[N];
int a[N];

int  run(int a[],int n){
	for(int i=0;i<n;i++){
		dp[i][i]=0;
	}
	for(int v=1;v<n;v++){
		for(int i=0;i<n-v;i++){
			int j=i+v;
			dp[i][j]=INF;
			int s=sum[j]-sum[i]+a[i];
			for(int k=i;k<j;k++){
				dp[i][j]=min(dp[i][k]+dp[k+1][j]+s,dp[i][j]);
			}
		}
	}

	return dp[0][n-1];
}

int main(void){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sum[0]=a[0];
	for(int i=1;i<n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	cout<<run(a,n)<<endl;

	return 0;
}