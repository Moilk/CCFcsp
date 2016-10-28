#include <iostream>

using namespace std;

unsigned short matrix[1000][1000];

int main(void){
	int N,M;
	cin>>N>>M;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin>>matrix[i][j];
		}
	}
	for(int j=M-1;j>=0;j--){
		for(int i=0;i<N;i++){
			cout<<matrix[i][j]<<' ';
		}
		cout<<endl;
	}
	
	return 0;
} 
