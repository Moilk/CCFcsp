#include <iostream>

using namespace std;

int main(void) {
	string str;
	cin>>str;
	int n=0,i=1,sum=0;
	while(n<11) {
		char c=str[n];
		if(c!='-') {
			sum+=(i++)*(c-'0');
		}
		n++;
	}
	sum%=11;
	if(sum==10){
		sum='X';
	}else{
		sum+='0';
	}
	if(sum==str[12]) {
		cout<<"Right"<<endl;
	} else {
		str[12]=sum;
		cout<<str<<endl;
	}

	return 0;
}
