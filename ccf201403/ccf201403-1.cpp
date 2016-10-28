#include <iostream>

using namespace std;

int main(void){
	int vec[500];
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>vec[i];
	}
	int key;
	int res=0;
	for(int i=0;i<N-1;i++){
		key=-vec[i];
		if(key==0){
			continue;
		}
		for(int j=i+1;j<N;j++){
			if(key==vec[j]){
				res++;
				vec[i]=vec[j]=0;
				break;
			}
		}
	}
	cout<<res<<endl;
	
	return 0;
} 
