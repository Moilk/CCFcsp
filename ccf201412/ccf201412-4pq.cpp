#include <iostream>
#include <queue>

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
int id[1005];
int sz[1005];
priority_queue<Edge> edges;

int _find(int p){
	if(p==id[p]){
		return p;
	}
	
	return id[p]=_find(id[p]);
}

bool _union(int x,int y){
	x=_find(x);
	y=_find(y);
	if(x==y){
		return false;
	}
	if(sz[x]<sz[y]){
		id[x]=y;
		sz[y]+=sz[x];
	}else{
		id[y]=x;
		sz[x]+=sz[y];
	}
	
	return true;
}

int kruskal(){
	int res=0,count=0;
	Edge e;
	while(!edges.empty()&&count<n-1){
		e=edges.top();
		edges.pop();
		if(_union(e.x,e.y)){
			res+=e.value;
			count++;
		}		
	}
	
	return res;
}

int main(void){
	cin>>n>>m;
	int x,y,v;
	for(int i=0;i<m;i++){
		cin>>x>>y>>v;
		edges.push(Edge(x,y,v));
	}
	for(int i=0;i<=n;i++){
		id[i]=i;
		sz[i]=1;
	}
	cout<<kruskal()<<endl;
	
	return 0;
}
