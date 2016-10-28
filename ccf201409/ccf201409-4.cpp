#include <iostream>
#include <queue>

using namespace std;

class P {
	public:
		int x,y,step;
		P(){
			x=y=step=0;
		}
		P(int xx,int yy,int s) {
			x=xx,y=yy,step=s;
		}
};

int n,m,k,d;
bool vis[1001][1001]= {0};
int map[1001][1001]= {0};
int mov[4][2]= {0,1,0,-1,1,0,-1,0};
queue<P> sp;

long long bfs() {
	long long res=0;
	int ck=0;
	while(!sp.empty()) {
		P p=sp.front();
		sp.pop();
		for(int i=0; i<4; i++) {
			P tmp=p;
			tmp.x+=mov[i][0];
			tmp.y+=mov[i][1];
			tmp.step++;
			if(!vis[tmp.x][tmp.y]&&tmp.x>0&&tmp.x<=n&&tmp.y>0&&tmp.y<=n) {
				vis[tmp.x][tmp.y]=1;
				if(map[tmp.x][tmp.y]) {
					res+=tmp.step*map[tmp.x][tmp.y];
					ck++;
					if(ck>=k){
						return res;
					}
				}
				sp.push(tmp);
			}
		}
	}
	
	return -1;
}

int main(void) {
	int x,y,z;
	cin>>n>>m>>k>>d;
	for(int i=0; i<m; i++) {
		cin>>x>>y;
		vis[x][y]=true;
		sp.push(P(x,y,0));
	}
	for(int i=0; i<k; i++) {
		cin>>x>>y>>z;
		map[x][y]=z;
	}
	for(int i=0; i<d; i++) {
		cin>>x>>y;
		vis[x][y]=true;
	}
	cout<<bfs()<<endl;

	return 0;
}
