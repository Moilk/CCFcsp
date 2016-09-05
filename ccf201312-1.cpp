#include <iostream>
#include <vector>

using namespace std;

struct Num{
	int n;
	int c;
};

bool cmp(Num &a,Num &b){
	if(a.c<b.c){
		return false;
	}
	if(a.c>b.c){
		return true;
	}
	if(a.n>b.n){
		return false;
	}
	return true;
}

int main(void){
	int N,tmp;
	vector<Num> num;
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>tmp;
		int len=num.size();
		bool ok=false;
		int j=0;
		for(;j<len;j++){
			if(tmp==num[j].n){
				num[j].c+=1;
				ok=true;
				break;
			}
		}
		if(!ok){
			Num newN;
			newN.c=1;
			newN.n=tmp;
			num.push_back(newN);
		}
	}
	int len=num.size();
	Num min=num[0];
	for(int i=1;i<len;i++){
		if(min.c<num[i].c||min.c==num[i].c&&min.n>num[i].n){
			min=num[i];
		}
	}
	
	cout<<min.n<<endl;
	
	return 0;
}
