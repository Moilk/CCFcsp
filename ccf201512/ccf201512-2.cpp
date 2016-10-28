#include <iostream>

using namespace std;

int mp[31][31];
bool marked[31][31];

int main(void) {
	int N,M;
	cin>>N>>M;
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			cin>>mp[i][j];
		}
	}
	for(int i=0; i<N; i++) {
		int key=mp[i][0];
		int count=1;
		for(int j=1; j<M; j++) {
			if(key==mp[i][j]) {
				count++;
				if(count==3) {
					marked[i][j-2]=marked[i][j-1]=marked[i][j]=1;
				}
				if(count>3) {
					marked[i][j]=1;
				}
			} else {
				key=mp[i][j];
				count=1;
			}
		}
	}

	for(int j=0; j<M; j++) {
		int key=mp[0][j];
		int count=1;
		for(int i=1; i<N; i++) {
			if(key==mp[i][j]) {
				count++;
				if(count==3) {
					marked[i-2][j]=marked[i-1][j]=marked[i][j]=1;
				}
				if(count>3) {
					marked[i][j]=1;
				}
			} else {
				key=mp[i][j];
				count=1;
			}
		}
	}



	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			cout<<(marked[i][j]?0:mp[i][j])<<' ';
		}
		cout<<endl;
	}

	return 0;
}
