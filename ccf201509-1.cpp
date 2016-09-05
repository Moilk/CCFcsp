#include <iostream>

using namespace std;

int main(void){
	int N,pre=-1,post,res=0;
	cin>>N;
	
	for(int i=0;i<N;i++){
		cin>>post;
		if(post!=pre){
			pre=post;
			res++;
		}
	}
	cout<<res<<endl;
	
	return 0;
}
