#include <iostream>
#include <cstring>

using namespace std;

char board[100][100];
bool marked[100][100];
int M,N,Q;

void _fill(int x,int y,char c) {
	if(x<0||x>=M||y<0||y>=N) {
		return;
	}
	if(marked[y][x]) {
		return;
	}
	char b=board[y][x];
	if(b=='|'||b=='-'||b=='+') {
		return;
	}
	board[y][x]=c;
	marked[y][x]=true;
	_fill(x-1,y,c);
	_fill(x+1,y,c);
	_fill(x,y-1,c);
	_fill(x,y+1,c);
}

void _draw(int x1,int y1,int x2,int y2) {
	int x=x1;
	int y=y1;
	if(x1-x2==0) {
		int dy=y1<y2?1:-1;
		y2+=dy;
		while(y!=y2) {
			if(board[y][x]=='-') {
				board[y][x]='+';
			} else if(board[y][x]!='+') {
				board[y][x]='|';
			}
			y+=dy;
		}
	} else {
		int dx=x1<x2?1:-1;
		x2+=dx;
		while(x!=x2){
			if(board[y][x]=='|'){
				board[y][x]='+';
			}else if(board[y][x]!='+'){
				board[y][x]='-';
			}
			x+=dx;
		}
	}
}

int main(void) {
	int op,x1,y1,x2,y2;
	char c;
	cin>>M>>N>>Q;

	memset(board,'.',sizeof(board));
	for(int i=0; i<Q; i++) {
		cin>>op;
		if(op) {
			cin>>x1>>y1>>c;
			_fill(x1,y1,c);
			memset(marked,0,sizeof(marked));
		} else {
			cin>>x1>>y1>>x2>>y2;
			_draw(x1,y1,x2,y2);
		}
	}

	for(int k=N-1; k>=0; k--) {
		for(int j=0; j<M; j++) {
			cout<<board[k][j];
		}
		cout<<endl;
	}

	return 0;
}
