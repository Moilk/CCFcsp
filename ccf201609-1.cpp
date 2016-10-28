#include <iostream>

using namespace std;

int main(void){
	int pre,post,mmax=0;
	int N;
	cin>>N;
	cin>>pre;
	for(int i=1;i<N;i++){
		cin>>post;
		int tmax=post-pre;
		tmax=tmax>=0?tmax:-tmax;
		mmax=max(tmax,mmax);
		pre=post;
	}
	cout<<mmax<<endl;

	return 0;
}