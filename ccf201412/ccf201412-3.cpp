#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

struct S {
	float cost;
	long long num;
	bool buy;
	int c;

	S(float f=-1,long long n=0,bool b=false,int cc=0) {
		cost=f,num=n,buy=b,c=cc;
	}
};

S cord[5000];
int mark[5000]= {0};

int main(void) {
	string str;
	float co;
	long long nu;
	int n=0;
	while(cin>>str) {
		switch(str[0]) {
			case 'b':
				cin>>co>>nu;
				cord[n]=S(co,nu,true,1);
				break;
			case 's':
				cin>>co>>nu;
				cord[n]=S(co,nu,false,1);
				break;
			case 'c':
				cin>>nu;
				cord[n]=S();
				cord[nu-1].c=cord[nu-1].c?0:1;
				break;
		}
		n++;
	}
	float bc=0;
	long long nn=0;
	for(int i=0; i<n; i++) {
		if(mark[i]||cord[i].cost<0) {
			continue;
		}
		float c=cord[i].cost;
		long long bn=0,sn=0;
		for(int j=0; j<n; j++) {
			if(cord[j].cost<0){
				continue;
			}
			if(cord[j].cost==c) {
				mark[j]=1;
				if(cord[j].buy) {
					bn+=cord[j].num*cord[j].c;
				} else {
					sn+=cord[j].num*cord[j].c;
				}
			} else if(cord[j].cost>c&&cord[j].buy) {
				bn+=cord[j].num*cord[j].c;
			} else if(cord[j].cost<c&&!cord[j].buy){
				sn+=cord[j].num*cord[j].c;
			}
		}
		long long mi=min(bn,sn);
		if(mi>nn||mi==nn&&c>bc) {
			nn=mi,bc=c;
		}
	}
	printf("%.2f %lld\n",bc,nn);

	return 0;
}
