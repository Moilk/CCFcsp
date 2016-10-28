#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TM {
	int s,v;
	TM(int ss=0,int vv=0) {
		s=ss,v=vv;
	}
};

struct S {
	int x,y,step;
	S(int xx=0,int yy=0,int ss=0) {
		x=xx,y=yy,step=ss;
	}
};

int N,M,T;
int mp[102][102];
bool marked[300][102][102];
vector<TM> tms;
int _go[][2]= {{0,1},{1,0},{0,-1},{-1,0}};

int bfs() {
	queue<S> que;
	que.push(S(1,1,0));
	while(!que.empty()) {
		S s=que.front();
		que.pop();
		if(s.x==N&&s.y==M) {
			return s.step;
		}
		for(int i=0; i<4; i++) {
			S tmp=s;
			tmp.x+=_go[i][0];
			tmp.y+=_go[i][1];
			tmp.step++;
			if(tmp.x<=0||tmp.x>N||tmp.y<=0||tmp.y>M){
				continue;
			}
			int index=mp[tmp.x][tmp.y];
			if(tmp.step>=300||index>0&&tmp.step>=tms[index].s&&tmp.step<=tms[index].v) {
				continue;
			}
			if(!marked[tmp.step][tmp.x][tmp.y]) {
				que.push(tmp);
				marked[tmp.step][tmp.x][tmp.y]=true;
			}
		}
	}

	return -1;
}

int main(void) {
	int r,c,a,b;
	cin>>N>>M>>T;
	int count=1;
	tms.push_back(TM());
	for(int i=0; i<T; i++) {
		cin>>r>>c>>a>>b;
		tms.push_back(TM(a,b));
		mp[r][c]=count;
		count++;
	}

	cout<<bfs()<<endl;

	return 0;
}
