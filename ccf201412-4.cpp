// kruskal最小生成树算法 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge{
	int x,y,value;
	Edge(int xx=0,int yy=0,int v=0){
		x=xx,y=yy,value=v;
	}
};
int n,m;
int id[1001];
int sz[1001]={1};
vector<Edge> edges;

bool cmp(Edge a,Edge b){
	return (a.value<b.value);
}

int _find(int p){
	if(p==id[p])	return p;
	
	return id[p]=_find(id[p]);	// 路径压缩 
}

bool _union(int x,int y){
	x=_find(x);
	y=_find(y);
	if(x==y){
		return false;
	}
	if(sz[x]<sz[y]){	// 小树接大树 
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
	for(int i=0;i<m;i++){
		if(_union(edges[i].x,edges[i].y)){
			res+=edges[i].value;
			count++;
			if(count==n-1){
				break;
			}
		}
	}
	
	return res;
}

int main(void){
	cin>>n>>m;
	int x,y,v;
	for(int i=0;i<m;i++){
		cin>>x>>y>>v;
		edges.push_back(Edge(x,y,v));
	}
	for(int i=0;i<=n;i++){
		id[i]=i;
	}
	sort(edges.begin(),edges.end(),cmp);
	cout<<kruskal()<<endl;
	
	return 0;
}
