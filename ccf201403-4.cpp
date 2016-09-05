#include <iostream>
#include <queue>

using namespace std;

struct Pn2 {
	int x;
	int y;
};

struct P{
	int x;
	int ck;
	int step;
	P(int xx=0,int c=0,int s=0){
		x=xx,ck=c,step=s;
	}
};

bool connected(Pn2 p1,Pn2 p2,long long rr) {
	long long xx=p1.x-p2.x;
	long long yy=p1.y-p2.y;
	if((xx*xx+yy*yy)<=rr) {
		return true;
	}
	return false;
}

bool map[200][200]= {0};
bool vis[200]= {0};
int n,m,k;
long long r;

int bfs() {
	P p,tmp;
	queue<P> sp;
	sp.push(P());
	int sum=n+m;
	int res=0,ck=0;
	while(!sp.empty()) {
		p=sp.front();
		vis[0]=1;
		sp.pop();
		for(int i=1; i<sum; i++) {
			if(p.ck==k&&i>=n){
				continue;
			}
			if(map[p.x][i]) {
				if(!vis[i]) {
					vis[i]=1;
					if(i==1) {
						return p.step;
					}
					tmp=p;
					tmp.x=i;
					tmp.step++;
					if(i>=n) {
						tmp.ck++;
					}
					sp.push(tmp);
				}
			}
		}
	}

	return -1;
}

int main(void) {
	Pn2 pns[200];

	cin>>n>>m>>k>>r;
	int sum=n+m;
	for(int i=0; i<sum; i++) {
		cin>>pns[i].x>>pns[i].y;
	}
	long long rr=r*r;
	for(int i=0; i<sum-1; i++) {
		for(int j=i+1; j<sum; j++) {
			if(connected(pns[i],pns[j],rr)) {
				map[i][j]=map[j][i]=1;
			}
		}
	}
	cout<<bfs()<<endl;

	return 0;
}
