#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Edge{
	int x,y,value;
	Edge(int xx=0,int yy=0,int v=0){
		x=xx,y=yy,value=v;
	}
	friend bool operator<(Edge a,Edge b){
		return a.value>b.value;
	}
};

int n,m;
vector<Edge> mp[1005];
bool marked[1005];
priority_queue<Edge> pq;

void visit(int v){
	marked[v]=true;
	Edge e;
	for(int i=0;i<mp[v].size();i++){
		e=mp[v][i];
		if(!marked[e.y]){
			pq.push(e);
		}
	}
}

int prim(){
	int res=0;
	Edge e;
	visit(1);
	while(!pq.empty()){
		e=pq.top();
		pq.pop();
		int x=e.x,y=e.y;
		if(marked[x]&&marked[y]){
			continue;
		}
		res+=e.value;
		if(!marked[x]){
			visit(x);
		}
		if(!marked[y]){
			visit(y);
		}
	}
	
	return res;
}

int main(void){
	cin>>n>>m;
	int x,y,v;
	for(int i=0;i<m;i++){
		cin>>x>>y>>v;
		mp[x].push_back(Edge(x,y,v));
		mp[y].push_back(Edge(y,x,v));
	}
	
	cout<<prim()<<endl;
	
	return 0;
}
