#include <iostream>

using namespace std;

int main(void){
	int N;
	int vec[1000];
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>vec[i];
	}
	int res=0;
	for(int i=0;i<N-1;i++){
		int c=0;
		for(int j=i+1;j<N;j++){
			if(vec[i]==vec[j]+1||vec[j]==vec[i]+1){
				c++;
			}
			if(c==2){
				break;
			}
		}
		res+=c;
	}
	cout<<res<<endl;
	
	return 0;
}
