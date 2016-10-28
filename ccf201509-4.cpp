#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <cstring>

using namespace std;

vector<int> *mp;
vector<int> *remap;
stack<int> rePost;
map<int,int> res;
bool *marked;
int count;
int N,M;

void dfs(vector<int> *G,int v,bool st) {
	marked[v]=true;
	if(!st) {
		res[count]++;
	}
	int len=G[v].size();
	for(int i=0; i<len; i++) {
		if(!marked[G[v][i]]) {
			dfs(G,G[v][i],st);
		}
	}
	if(st) {
		rePost.push(v);
	}
}

void kosaraju() {
	memset(marked,0,N+1);
	for(int v=1; v<=N; v++) {
		if(!marked[v]) {
			dfs(remap,v,true);
		}
	}
	memset(marked,0,N+1);
	while(!rePost.empty()) {
		int s=rePost.top();
		rePost.pop();
		if(!marked[s]) {
			dfs(mp,s,false);
			count++;
		}
	}
}

int main(void) {
	int s,e;
	cin>>N>>M;

	mp=new vector<int>[N+1];
	remap=new vector<int>[N+1];
	marked=new bool[N+1];

	for(int i=0; i<M; i++) {
		cin>>s>>e;
		mp[s].push_back(e);
		remap[e].push_back(s);
	}

	kosaraju();
	int ans=0;
	for(int i=0;i<count;i++){
		if(res[i]>=2){
			ans+=res[i]*(res[i]-1)/2;
		}
	}
	cout<<ans<<endl;

	delete mp;
	delete remap;
	delete marked;
	return 0;
}
