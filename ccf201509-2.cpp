#include <iostream>

using namespace std;

int day[]={0,31,28,31,30,31,30,31,31,30,31,30,31};

bool isLeap(int yyyy){
	if(yyyy%4==0&&yyyy%100!=0||yyyy%400==0){
		return true;
	}
	return false;
}

int main(void){
	int yyyy,dy;
	cin>>yyyy>>dy;
	if(isLeap(yyyy)){
		day[2]=29;
	}else{
		day[2]=28;
	}
	int mm=1,dd=0;
	for(int i=1;i<=12;i++){
		if(dy<=day[i]){
			break;
		}
		dy-=day[i];
		mm++;
	}
	cout<<mm<<endl<<dy<<endl;
	
	return 0;
}
