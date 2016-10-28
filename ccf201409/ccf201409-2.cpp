#include <iostream>

using namespace std;

int main(void){
	int N,x1,x2,y1,y2;
	int board[101][101]={0};
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>x1>>y1>>x2>>y2;
		for(int m=x1;m<x2;m++){
			for(int n=y1;n<y2;n++){
				board[m][n]=1;
			}
		}
	}
	int res=0;
	for(int i=0;i<=100;i++){
		for(int j=0;j<=100;j++){
			if(board[i][j]){
				res++;
			}
		}
	}
	cout<<res<<endl;
	
	return 0;
}
