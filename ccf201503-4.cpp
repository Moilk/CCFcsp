#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct P {
	int v;
	int step;
	P(int vv=0,int s=0) {
		v=vv,step=s;
	}
};

vector<int> map[20001];
bool marked[20001]= {0};

int bfs(int s,int &e) {
	queue<P> que;
	que.push(P(s));
	marked[s]=1;
	int res=0;
	P p,pp;
	while(!que.empty()) {
		p=que.front();
		que.pop();
		int len=map[p.v].size();
		for(int i=0; i<len; i++) {
			int tmp=map[p.v][i];
			if(!marked[tmp]) {
				marked[tmp]=1;
				e=tmp;
				pp=P(tmp);
				pp.step=p.step+1;
				que.push(pp);
			}
		}
	}

	return pp.step;
}

int main(void) {
	int N,M,fa;
	cin>>N>>M;
	for(int i=2; i<=N; i++) {
		cin>>fa;
		map[fa].push_back(i);
		map[i].push_back(fa);
	}
	for(int i=1; i<=M; i++) {
		cin>>fa;
		map[fa].push_back(N+i);
		map[N+i].push_back(fa);
	}
	int e,res;
	bfs(1,e);
	for(int i=0;i<20001;i++){
		marked[i]=0;
	}
	cout<<bfs(e,res)<<endl;

	return 0;
}
