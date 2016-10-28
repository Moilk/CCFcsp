#include <iostream>

using namespace std;

bool board[16][15];
bool block[5][5];
int top[]={16,16,16,16,16};
int bottom[]={0,0,0,0,0};

int main(void){
	int pos;
	for(int i=1;i<=15;i++){
		for(int j=1;j<=10;j++){
			cin>>board[i][j];
		}
	}
	for(int i=1;i<=4;i++){
		for(int j=1;j<=4;j++){
			cin>>block[i][j];
		}
	}
	cin>>pos;
	for(int j=1;j<=4;j++){
		for(int i=1;i<=15;i++){
			if(board[i][j+pos-1]){
				top[j]=i;
				break;
			}
		}
	}
	for(int j=1;j<=4;j++){
		for(int i=4;i>=1;i--){
			if(block[i][j]){
				bottom[j]=i;
				break;
			}
		}
	}
	
	int min=99;
	for(int i=1;i<=4;i++){
		int tmp=15;
		if(bottom[i]){
			tmp=top[i]-bottom[i];
		}
		if(tmp<min){
			min=tmp;
		}
	}
	
	for(int i=min;i<=15;i++){
		for(int j=pos;j<=pos+3;j++){
			if(block[i-min+1][j-pos+1]){
				board[i][j]=1;
			}
		}
	}
		
	for(int i=1;i<=15;i++){
		for(int j=1;j<=10;j++){
			cout<<board[i][j]<<' ';
		}
		cout<<endl;
	}
	
	return 0;
}
