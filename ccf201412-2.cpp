#include <iostream>

using namespace std;

int vec[500][500];
enum DIR {
    RIGHT_UP,RIGHT,LEFT_DOWN,DOWN
};

int main(void) {
	int N;
	cin>>N;
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			cin>>vec[i][j];
		}
	}
	int i=0,j=0;
	int dir=RIGHT;
	bool ok=true;
	while(1) {
		cout<<vec[i][j]<<' ';
		if(i==N-1&&j==N-1) {
			break;
		}
		ok=false;
		switch(dir) {
			case RIGHT_UP:
				if(j+1==N) {
					i++;
					dir=LEFT_DOWN;
				} else if(i-1==-1) {
					j++;
					dir=LEFT_DOWN;
				} else {
					i--;
					j++;
				}
				break;
			case RIGHT:
				if(j+1==N) {
					i++;
					dir=LEFT_DOWN;
				} else {
					j++;
					if(i==0) {
						dir=LEFT_DOWN;
					} else {
						dir=RIGHT_UP;
					}
				}
				break;
			case LEFT_DOWN:
				if(i+1==N) {
					j++;
					dir=RIGHT_UP;
				} else if(j-1==-1) {
					i++;
					dir=RIGHT_UP;
				} else {
					i++;
					j--;
				}
				break;
			case DOWN:
				if(i+1==N) {
					j++;
					dir=RIGHT_UP;
				} else {
					i++;
					if(j==0){
						dir=RIGHT_UP;
					}else{
						dir=LEFT_DOWN;
					}
				}
				break;
		}
	}
	cout<<endl;

	return 0;
}
