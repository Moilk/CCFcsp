#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

map<int,int> mp;

int main(void){
	int N,tmp;
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>tmp;
		if(!mp[tmp]){
			cout<<1<<' ';
			mp[tmp]=1;
		}else{
			mp[tmp]++;
			cout<<mp[tmp]<<' ';
		}
	}
	cout<<endl;
	
	return 0;
}
