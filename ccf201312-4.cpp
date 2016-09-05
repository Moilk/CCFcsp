#include <iostream>

using namespace std;

// 排列组合解决 
int main(void) {
	int N;
	cin>>N;
	long long res=1;
	int co=N-3;
	
	// 快速计算2的幂 
	while(co>0) {
		if(co>=19) {
			res<<=19;
		} else {
			res<<=co;
		}
		if(res>=1000000007) {
			res%=1000000007;
		}
		co-=19;
	}

	res=(res*(N*N-5*N+4)+N-1)%1000000007;
	cout<<res<<endl;

	return 0;
}
