#include <iostream>
#include <cstdio>

using namespace std;

int main(void){
	char c;
	int res=0;
	while((c=getchar())!='\n'){
		res+=c-'0';
	}
	cout<<res<<endl;
	
	return 0;
}
