#include <iostream>
#include <cstdio>

using namespace std;

int day[]= {0,31,28,31,30,31,30,31,31,30,31,30,31};

bool isLeap(int yyyy) {
	if(yyyy%4==0&&yyyy%100!=0||yyyy%400==0) {
		return true;
	}
	return false;
}

int main(void) {
	int a,b,c,y1,y2;
	cin>>a>>b>>c>>y1>>y2;
	int dys=0;
	for(int i=1850; i<y1; i++) {
		if(isLeap(i)) {
			dys++;
		}
		dys+=365;
	}
	for(int yyyy=y1; yyyy<=y2; yyyy++) {
		int dd=dys;
		for(int i=y1; i<yyyy; i++) {
			if(isLeap(i)) {
				dd++;
			}
			dd+=365;
		}
		if(isLeap(yyyy)) {
			day[2]=29;
		} else {
			day[2]=28;
		}
		for(int i=1; i<a; i++) {
			dd+=day[i];
		}
		// yyyy年a月1日是星期几
		int week=2+dd%7;
		int dms=1+(b-1)*7+(c>=week?(c-week):(c+7-week));
		if(dms>day[a]){
			cout<<"none"<<endl;
		}else{
			printf("%d/%02d/%02d\n",yyyy,a,dms);
		}

	}
	
	return 0;
}
