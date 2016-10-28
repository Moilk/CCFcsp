#include <iostream>

using namespace std;

long long mymod(long long d){
	if(d>=1000000007){
		d%=1000000007;
	}
	return d;
}

// 动态规划解决 
int main(void){
	int N;
	cin>>N;
	long long m[1001][6]={0};
	
	for(int i=1;i<=N;i++){
		m[i][0]=1;
		m[i][1]=mymod(m[i-1][0]+m[i-1][1]);
		m[i][2]=mymod(m[i-1][0]+m[i-1][2]*2);
		m[i][3]=mymod(m[i-1][1]+m[i-1][2]+m[i-1][3]*2);
		m[i][4]=mymod(m[i-1][2]+m[i-1][4]*2);
		m[i][5]=mymod(m[i-1][3]+m[i-1][4]+m[i-1][5]*2);
	}
	cout<<m[N][5]<<endl;
	
	return 0;
}
