#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<unsigned short,unsigned short> PAIR;

map<unsigned short,unsigned short> mp;
vector<PAIR> vec;

bool cmp(PAIR a,PAIR b){
	if(a.second>b.second){
		return true;
	}
	if(a.second<b.second){
		return false;
	}
	if(a.first>b.first){
		return false;
	}
	return true;
}

int main(void){
	int N;
	unsigned short tmp;
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>tmp;
		mp[tmp]++;
	}
	for(map<unsigned short,unsigned short>::iterator it=mp.begin();it!=mp.end();it++){
		vec.push_back(*it);
	}
	sort(vec.begin(),vec.end(),cmp);
	for(vector<PAIR>::iterator it=vec.begin();it!=vec.end();it++){
		cout<<it->first<<' '<<it->second<<endl;
	}
	
	return 0;
} 
