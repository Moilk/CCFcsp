#include <iostream>
#include <vector>

using namespace std;

struct Node {
	int r;
	int c;
	Node(int rr=0,int cc=0) {
		r=rr,c=cc;
	}
};

int R,C;
Node S,T;
int mov[][2]= {1,0,-1,0,0,-1,0,1};
char mp[55][55];
bool marked1[55][55];
bool marked2[55][55];
vector<Node>dir[5];

bool canMov(char a,char b,int r,int c) {
	if(b=='#') {
		return false;
	}
	
	if(a=='+'||a=='S'||a=='T') {
		return true;
	}
	
	if(a=='-'&&r==0) {
		return true;
	}
	
	if(a=='|'&&c==0) {
		return true;
	}
	
	if(a=='.'&&r==1&&c==0) {
		return true;
	}

	return false;
}

void dfs(Node s,bool marked[][55],bool re) {
	for(int i=0; i<4; i++) {
		Node tmp=s;
		tmp.r+=mov[i][0];
		tmp.c+=mov[i][1];
		if(!marked[tmp.r][tmp.c]) {
			if(!re&&canMov(mp[s.r][s.c],mp[tmp.r][tmp.c],mov[i][0],mov[i][1])||re&&canMov(mp[tmp.r][tmp.c],mp[s.r][s.c],-mov[i][0],-mov[i][1])) {
				marked[tmp.r][tmp.c]=true;
				dfs(tmp,marked,re);
			}
		}
	}
}

int main(void) {
	char c;
	cin>>R>>C;
	for(int i=1; i<=R; i++) {
		for(int j=1; j<=C; j++) {
			cin>>c;
			mp[i][j]=c;
			if(c=='S') {
				S.r=i;
				S.c=j;
			}
			if(c=='T') {
				T.r=i;
				T.c=j;
			}
		}
	}
	dfs(T,marked2,true);
	if(!marked2[S.r][S.c]) {
		cout<<"I'm stuck!"<<endl;
		return 0;
	}

	dfs(S,marked1,false);
	int res=0;
	for(int i=1; i<=R; i++) {
		for(int j=1; j<=C; j++) {
			if(marked1[i][j]&&!marked2[i][j]) {
				res++;
			}
		}
	}

	cout<<res<<endl;

	return 0;
}

