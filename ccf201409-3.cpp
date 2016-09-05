#include <iostream>
#include <algorithm>

using namespace std;

void run(string str,string key,int op){
	string locstr=str;
	if(op==0){
		transform(str.begin(),str.end(),locstr.begin(),::tolower);
		transform(key.begin(),key.end(),key.begin(),::tolower);
	}
	
	if(locstr.find(key)!=string::npos){
		cout<<str<<endl;
	}
}

int main(void){
	string key,str;
	int op,N;
	cin>>key;
	cin>>op;;
	cin>>N;
	
	for(int i=0;i<N;i++){
		cin>>str;
		run(str,key,op);
	}
	
	return 0;
}
